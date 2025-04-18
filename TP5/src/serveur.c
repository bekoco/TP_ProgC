/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <ctype.h>

#include "serveur.h"

int socketfd;

/**
 * Fonction pour évaluer une expression simple de type "a+b", "a-b", "a*b", "a/b"
 */
int evaluer_expression(const char *expr, int *resultat) {
  int a = 0, b = 0;
  char op = 0;
  if (sscanf(expr, "%d%c%d", &a, &op, &b) == 3) {
    switch (op) {
      case '+': *resultat = a + b; return 1;
      case '-': *resultat = a - b; return 1;
      case '*': *resultat = a * b; return 1;
      case '/':
        if (b == 0) return -1; // division par zéro
        *resultat = a / b;
        return 1;
      default: return 0; // opérateur invalide
    }
  }
  return 0; // format invalide
}

/**
 * Envoie un message au client
 */
int renvoie_message(int client_socket_fd, char *data) {
  int data_size = write(client_socket_fd, (void *)data, strlen(data));
  if (data_size < 0) {
    perror("Erreur d'écriture");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

/**
 * Traite les messages du client et renvoie une réponse
 */
int recois_envoie_message(int client_socket_fd, char *data) {
  printf("Message reçu: %s\n", data);
  char code[10], contenu[1024];

  if (sscanf(data, "%9[^:]:%1023[^\n]", code, contenu) == 2) {
    if (strcmp(code, "message") == 0) {
      int resultat = 0;
      int status = evaluer_expression(contenu, &resultat);

      char reponse[1024];
      if (status == 1) {
        snprintf(reponse, sizeof(reponse), "résultat: %d", resultat);
      } else if (status == -1) {
        snprintf(reponse, sizeof(reponse), "Erreur: division par zéro");
      } else {
        snprintf(reponse, sizeof(reponse), "Erreur: expression invalide");
      }

      return renvoie_message(client_socket_fd, reponse);
    }
  }

  return EXIT_SUCCESS;
}

/**
 * Gère Ctrl+C (SIGINT)
 */
void gestionnaire_ctrl_c(int signal) {
  printf("\nSignal Ctrl+C capturé. Sortie du programme.\n");
  if (socketfd != -1) {
    close(socketfd);
  }
  exit(0);
}

/**
 * Communication avec un client
 */
void gerer_client(int client_socket_fd) {
  char data[1024];
  while (1) {
    memset(data, 0, sizeof(data));
    int data_size = read(client_socket_fd, data, sizeof(data));

    if (data_size <= 0) {
      if (data_size == 0) {
        printf("Client déconnecté.\n");
      } else {
        perror("Erreur de réception");
      }
      close(client_socket_fd);
      break;
    }

    recois_envoie_message(client_socket_fd, data);
  }
}

/**
 * Point d'entrée principal
 */
int main() {
  int bind_status;
  struct sockaddr_in server_addr;
  int option = 1;

  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0) {
    perror("Impossible d'ouvrir une socket");
    return -1;
  }

  setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = inet_addr("10.0.30.5");

  bind_status = bind(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (bind_status < 0) {
    perror("bind");
    return EXIT_FAILURE;
  }

  signal(SIGINT, gestionnaire_ctrl_c);

  listen(socketfd, 10);
  printf("Serveur en attente de connexions...\n");

  struct sockaddr_in client_addr;
  unsigned int client_addr_len = sizeof(client_addr);
  int client_socket_fd;

  while (1) {
    client_socket_fd = accept(socketfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_socket_fd < 0) {
      perror("accept");
      continue;
    }

    pid_t child_pid = fork();

    if (child_pid == 0) {
      close(socketfd);
      gerer_client(client_socket_fd);
      exit(0);
    } else if (child_pid < 0) {
      perror("fork");
      close(client_socket_fd);
    } else {
      close(client_socket_fd);
    }
  }

  return 0;
}

/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef __SERVER_H__
#define __SERVER_H__

#define PORT 8089

/**
 * Envoie un message au client via le socket donné.
 * @param client_socket_fd : socket du client
 * @param sdata : message à envoyer
 * @return EXIT_SUCCESS ou EXIT_FAILURE
 */
int renvoie_message(int client_socket_fd, char *sdata);

/**
 * Reçoit un message du client, affiche ce message,
 * demande une réponse à l'utilisateur serveur, et la renvoie au client.
 * @param client_socket_fd : socket du client
 * @param data : message reçu
 * @return EXIT_SUCCESS ou EXIT_FAILURE
 */
int recois_envoie_message(int client_socket_fd, char *data);

/**
 * Gère la session complète avec un client :
 * réception, réponse, boucle, et déconnexion sur "exit"
 * @param client_socket_fd : socket du client
 */
void gerer_client(int client_socket_fd);

/**
 * Gère proprement le signal Ctrl+C (SIGINT)
 * pour fermer le socket serveur avant de quitter.
 * @param signal : le signal capturé
 */
void gestionnaire_ctrl_c(int signal);

#endif

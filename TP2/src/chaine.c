#include <stdio.h>
#include <stdlib.h>

int main() {
    char chaine1[] = "Hello";
    char chaine2[] = "World !";
    int len1 = 0, len2 = 0;

    while (chaine1[len1] != '\0') len1++;
    while (chaine2[len2] != '\0') len2++;

    // +1 pour l'espace, +1 pour '\0'
    char *chaine_finale = malloc(len1 + len2 + 2);

    // Copie de chaine1
    for (int i = 0; i < len1; i++) {
        chaine_finale[i] = chaine1[i];
    }

    // Ajout de l'espace
    chaine_finale[len1] = ' ';

    // Copie de chaine2
    for (int i = 0; i < len2; i++) {
        chaine_finale[len1 + 1 + i] = chaine2[i];
    }

    // Terminaison de la chaîne
    chaine_finale[len1 + 1 + len2] = '\0';

    // Affichage
    printf("%s\n", chaine_finale);

    // Libération mémoire
    free(chaine_finale);
    return 0;
}

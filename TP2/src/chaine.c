#include <stdio.h>

int main() {
    char chaine1[] = "Hello";
    char chaine2[] = "World !";
    int Length1 = 0;
    int Length2 = 0;

    // Calcul de la longueur de chaine1
    while (chaine1[Length1] != '\0') {
        Length1++;
    }

    // Calcul de la longueur de chaine2
    while (chaine2[Length2] != '\0') {
        Length2++;
    }

    // Espace + 1 caractère nul → +2
    char chaine_finale[100];

    // Copie de chaine1
    for (int i = 0; i < Length1; i++) {
        chaine_finale[i] = chaine1[i];
    }

    // Ajout de l'espace après chaine1
    chaine_finale[Length1] = ' ';

    // Copie de chaine2 à la suite de l'espace
    for (int i = 0; i < Length2; i++) {
        chaine_finale[Length1 + 1 + i] = chaine2[i];
    }

    // Ajout du caractère de fin
    chaine_finale[Length1 + 1 + Length2] = '\0';

    // Affichage de la chaîne finale
    printf("%s\n", chaine_finale);

    return 0;
}

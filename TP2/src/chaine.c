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

    // Tableau suffisamment grand, la taille doit être connue à la compilation
    char chaine_finale[100]; // On utilise une taille fixe ici

    // Copie de chaine1
    for (int i = 0; i < Length1; i++) {
        chaine_finale[i] = chaine1[i];
    }

    // Copie de chaine2 à la suite
    for (int i = 0; i < Length2; i++) {
        chaine_finale[Length1 + i] = chaine2[i];
    }

    // Ajout du caractère de fin
    chaine_finale[Length1 + Length2] = '\0';

    // Affichage de la chaîne finale
    printf("%s\n", chaine_finale);

    return 0;
}

#include <stdio.h>

int main() {
    int compteur = 5; // Tu peux modifier cette valeur entre 1 et 9

    if (compteur >= 10) {
        printf("Erreur : le compteur doit être strictement inférieur à 10.\n");
        return 1;
    }

    // Affichage du triangle rectangle
    for (int i = 1; i <= compteur; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}

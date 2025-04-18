#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100

int main() {
    int tableau[TAILLE];
    int i, a_rechercher;
    int trouve = 0;

    srand(time(NULL));

    for (i = 0; i < TAILLE; i++) {
        tableau[i] = (rand() % 1000) + 1;
    }

    printf("Tableau généré :\n");
    for (i = 0; i < TAILLE; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n\n");

    printf("Entrez l'entier à rechercher : ");
    scanf("%d", &a_rechercher);

    for (i = 0; i < TAILLE; i++) {
        if (tableau[i] == a_rechercher) {
            trouve = 1;
            break;
        }
    }

    if (trouve) {
        printf("Entier présent ✅\n");
    } else {
        printf("Entier absent ❌\n");
    }

    return 0;
}

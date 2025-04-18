#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100

int main() {
    int tableau[TAILLE];
    int min, max;

    srand(time(NULL));
    for (int i = 0; i < TAILLE; i++) {
        tableau[i] = (rand() % 1000) + 1;
    }

    min = tableau[0];
    max = tableau[0];

    for (int i = 1; i < TAILLE; i++) {
        if (tableau[i] < min) {
            min = tableau[i];
        }
        if (tableau[i] > max) {
            max = tableau[i];
        }
    }

    printf("=== Résultat ===\n");
    printf("Valeur minimale : %d\n", min);
    printf("Valeur maximale : %d\n", max);

    return 0;
}

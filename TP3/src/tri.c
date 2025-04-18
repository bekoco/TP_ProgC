#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100

int main() {
    int tab[TAILLE];
    int i, j, temp;

    srand(time(NULL));

    for (i = 0; i < TAILLE; i++) {
        tab[i] = (rand() % 1000) + 1;
    }

    printf("=== Tableau avant tri ===\n");
    for (i = 0; i < TAILLE; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n\n");

    for (i = 0; i < TAILLE - 1; i++) {
        for (j = 0; j < TAILLE - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }

    printf("=== Tableau après tri croissant ===\n");
    for (i = 0; i < TAILLE; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");

    return 0;
}

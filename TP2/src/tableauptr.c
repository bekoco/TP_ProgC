#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 10

int main() {
    int tab_int[TAILLE];
    float tab_float[TAILLE];

    srand(time(NULL));

    int *p_int = tab_int;
    float *p_float = tab_float;
  
    for (int i = 0; i < TAILLE; i++) {
        *(p_int + i) = rand() % 100;
        *(p_float + i) = (float)(rand() % 10000) / 100.0;
    }

    printf("=== Avant manipulation ===\n");
    printf("Tableau d'entiers :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%d ", *(p_int + i));
    }

    printf("\n\nTableau de flottants :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%.2f ", *(p_float + i));
    }

    for (int i = 0; i < TAILLE; i += 2) {
        *(p_int + i) *= 3;
        *(p_float + i) *= 3.0f;
    }

    printf("\n\n=== Après manipulation (indices pairs * 3) ===\n");
    printf("Tableau d'entiers :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%d ", *(p_int + i));
    }

    printf("\n\nTableau de flottants :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%.2f ", *(p_float + i));
    }

    printf("\n");

    return 0;
}

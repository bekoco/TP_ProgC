
#include <stdio.h>

int main() {
    int n = 5;  // Hauteur de la pyramide
    int i, j;

    for (i = 1; i <= n; i++) {
        // Affichage des espaces pour centrer les nombres
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // Affichage des nombres croissants de 1 à i
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // Affichage des nombres décroissants de i-1 à 1
        for (j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }

        // Nouvelle ligne après chaque niveau de la pyramide
        printf("\n");
    }

    printf("Pyramide terminée avec succès !\n");

    return 0;
}

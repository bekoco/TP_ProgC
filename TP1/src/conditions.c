#include <stdio.h>

int main() {
    int somme = 0;

    for (int i = 1; i <= 1000; i++) {
        // On ignore les multiples de 11
        if (i % 11 == 0) {
            continue;
        }

        // On vérifie s’il est divisible par 5 ou 7
        if (i % 5 == 0 || i % 7 == 0) {
            // Vérification avant l'ajout
            if (somme + i > 5000) {
                break;
            }
            somme += i;
            printf("Ajout de %d → somme = %d\n", i, somme);
        }
    }

    printf("\nSomme finale : %d\n", somme);

    return 0;
}

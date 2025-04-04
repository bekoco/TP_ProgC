#include <stdio.h>

int main() {
    int a = 2;        // Base
    int b = 3;        // Exposant
    int resultat = 1; // Résultat initialisé à 1

    for (int i = 0; i < b; i++) {
        resultat *= a; // Multiplie a par lui-même b fois
    }

    printf("%d élevé à la puissance %d est : %d\n", a, b, resultat);

    return 0;
}

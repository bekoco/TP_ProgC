#include <stdio.h>

void afficherBinaire(unsigned int n) {
    int i;
    int tailleBits = sizeof(n) * 8; // Généralement 32 bits

    int start = 0; // Pour ne pas afficher les 0 initiaux

    for (i = tailleBits - 1; i >= 0; i--) {
        int bit = (n >> i) & 1;

        if (bit == 1)
            start = 1;

        if (start)
            printf("%d", bit);
    }

    // Si le nombre est 0, on l'affiche quand même
    if (!start)
        printf("0");

    printf("\n");
}

int main() {
    unsigned int nombres[] = {0, 4096, 65536, 65535, 1024};
    int taille = sizeof(nombres) / sizeof(nombres[0]);

    for (int i = 0; i < taille; i++) {
        printf("Décimal : %u → Binaire : ", nombres[i]);
        afficherBinaire(nombres[i]);
    }

    return 0;
}

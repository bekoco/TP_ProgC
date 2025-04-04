#include <stdio.h>

int main() {
    unsigned int d = 0x00F00010; // Valeur à tester (modifie-la si besoin)
    int taille = sizeof(d) * 8;  // Nombre total de bits (ex: 32 bits sur la plupart des machines)

    // Position des bits à tester (en partant de la gauche)
    int pos4gauche = 4;
    int pos20gauche = 20;

    // Conversion en positions depuis la droite (bit 0 à droite)
    int pos4droite = taille - pos4gauche;
    int pos20droite = taille - pos20gauche;

    // Masques pour extraire les bits
    int bit4 = (d >> pos4droite) & 1;
    int bit20 = (d >> pos20droite) & 1;

    // Affichage du résultat
    if (bit4 == 1 && bit20 == 1) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define TAILLE 100

typedef struct {
    uint8_t r, g, b, a;
} CouleurRGBA;

int comparer_couleurs(CouleurRGBA c1, CouleurRGBA c2) {
    return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a;
}

int main() {
    CouleurRGBA couleurs[TAILLE];
    CouleurRGBA uniques[TAILLE];
    int compte[TAILLE] = {0};
    int nb_uniques = 0;

    srand(time(NULL));

    for (int i = 0; i < TAILLE; i++) {
        couleurs[i].r = rand() % 256;
        couleurs[i].g = rand() % 256;
        couleurs[i].b = rand() % 256;
        couleurs[i].a = 255; 
    }

    for (int i = 0; i < TAILLE; i++) {
        int trouvé = 0;
        for (int j = 0; j < nb_uniques; j++) {
            if (comparer_couleurs(couleurs[i], uniques[j])) {
                compte[j]++;
                trouvé = 1;
                break;
            }
        }
        if (!trouvé) {
            uniques[nb_uniques] = couleurs[i];
            compte[nb_uniques] = 1;
            nb_uniques++;
        }
    }

    printf("=== Couleurs distinctes (%d au total) ===\n\n", nb_uniques);
    for (int i = 0; i < nb_uniques; i++) {
        printf("Couleur %d → R:%3d G:%3d B:%3d A:%3d : %d fois\n",
               i + 1,
               uniques[i].r, uniques[i].g, uniques[i].b, uniques[i].a,
               compte[i]);
    }

    return 0;
}

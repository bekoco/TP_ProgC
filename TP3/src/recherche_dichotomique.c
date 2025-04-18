#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 100

// Fonction de tri simple (tri à bulles)
void trier(int t[], int taille) {
    for (int i = 0; i < taille - 1; i++) {
        for (int j = 0; j < taille - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                int temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
}

// Recherche dichotomique
int recherche_dicho(int t[], int taille, int cible) {
    int debut = 0;
    int fin = taille - 1;

    while (debut <= fin) {
        int milieu = (debut + fin) / 2;

        if (t[milieu] == cible) {
            return 1; // trouvé
        } else if (t[milieu] < cible) {
            debut = milieu + 1;
        } else {
            fin = milieu - 1;
        }
    }

    return 0; // non trouvé
}

int main() {
    int tab[TAILLE];
    int cible;

    srand(time(NULL));

    for (int i = 0; i < TAILLE; i++) {
        tab[i] = (rand() % 1000) + 1;
    }

    trier(tab, TAILLE);

    printf("Tableau trié :\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n\n");

    printf("Entrez l'entier à rechercher : ");
    scanf("%d", &cible);

    if (recherche_dicho(tab, TAILLE, cible)) {
        printf("Entier présent ✅\n");
    } else {
        printf("Entier absent ❌\n");
    }

    return 0;
}

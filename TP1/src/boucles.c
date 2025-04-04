#include <stdio.h>

int main() {
    int compteur = 5; // Change cette valeur pour tester

    if (compteur >= 10) {
        printf("Le compteur doit être strictement inférieur à 10.\n");
        return 1;
    }

    for (int i = 1; i <= compteur; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == 1 || i == compteur || j == 1 || j == i) {
                printf("* ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }

    return 0;
}

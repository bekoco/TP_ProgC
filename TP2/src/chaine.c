#include <stdio.h>

int main() {
    char source[] = "Bonjour";
    char destination[100];
    char ajout[] = " le monde";

    // 1. Calculer la longueur
    int longueur = 0;
    while (source[longueur] != '\0') {
        longueur++;
    }
    printf("Longueur de source : %d\n", longueur);

    // 2. Copier source → destination
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
    printf("Après copie : %s\n", destination);

    // 3. Concaténer ajout → destination
    int j = 0;
    while (ajout[j] != '\0') {
        destination[i] = ajout[j];
        i++;
        j++;
    }
    destination[i] = '\0';
    printf("Après concaténation : %s\n", destination);

    return 0;
}

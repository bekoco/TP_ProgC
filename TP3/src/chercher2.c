#include <stdio.h>

#define TAILLE 10
#define MAX_LEN 100

int comparer_chaine(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return 0; 
        }
        i++;
    }
    return (s1[i] == '\0' && s2[i] == '\0'); 
}

int main() {
    char phrases[TAILLE][MAX_LEN] = {
        "Bonjour tout le monde",
        "Je m'appelle Pierre",
        "Il fait beau aujourd'hui",
        "Ceci est un test",
        "Le C est puissant",
        "Apprendre à coder",
        "La programmation est fun",
        "Bienvenue chez toi",
        "Quel beau projet",
        "C'est la fin"
    };

    char recherche[MAX_LEN];
    int trouvée = 0;

    printf("Entrez la phrase à rechercher :\n");
    fgets(recherche, MAX_LEN, stdin);

    for (int i = 0; i < MAX_LEN; i++) {
        if (recherche[i] == '\n') {
            recherche[i] = '\0';
            break;
        }
    }

    for (int i = 0; i < TAILLE; i++) {
        if (comparer_chaine(phrases[i], recherche)) {
            trouvée = 1;
            break;
        }
    }

    if (trouvée) {
        printf("Phrase trouvée ✅\n");
    } else {
        printf("Phrase absente ❌\n");
    }

    return 0;
}

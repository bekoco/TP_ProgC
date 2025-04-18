#include <stdio.h>
#include <string.h>

#define TAILLE 5
#define LONGUEUR 50

int main() {
    char noms[TAILLE][LONGUEUR] = {
        "Dupont", "Nguyen", "Smith", "Tchana", "Diaz"
    };
    
    char prenoms[TAILLE][LONGUEUR] = {
        "Marie", "Linh", "John", "Pierre", "Sofia"
    };
    
    char adresses[TAILLE][100] = {
        "10 rue des Lilas, Paris", 
        "25 avenue du Soleil, Lyon", 
        "123 Main Street, Londres", 
        "4 impasse des Roses, Yaoundé", 
        "56 boulevard Central, Madrid"
    };
    
    float notes_progC[TAILLE] = {15.5, 17.0, 12.5, 14.0, 16.5};
    float notes_systeme[TAILLE] = {13.0, 16.5, 14.5, 15.0, 18.0};
    
    printf("=== Informations des étudiant.e.s ===\n\n");

    for (int i = 0; i < TAILLE; i++) {
        printf("Étudiant %d :\n", i + 1);
        printf("Nom       : %s\n", noms[i]);
        printf("Prénom    : %s\n", prenoms[i]);
        printf("Adresse   : %s\n", adresses[i]);
        printf("Note Prog C       : %.2f\n", notes_progC[i]);
        printf("Note Système d'Exploitation : %.2f\n", notes_systeme[i]);
        printf("--------------------------------------\n");
    }

    return 0;
}

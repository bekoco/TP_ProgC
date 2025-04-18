#include <stdio.h>

#define TAILLE 5

// Structure Etudiant
struct Etudiant {
    char nom[100];
    char prenom[100];
    char adresse[200];
    float note_prog_c;
    float note_sys_exp;
};

int main() {
    struct Etudiant etudiants[TAILLE] = {
        {"Dupont", "Alice", "12 rue des Lilas, Paris", 14.5, 16.0},
        {"Martin", "Lucas", "5 avenue Victor Hugo, Lyon", 11.0, 12.5},
        {"Nguyen", "Linh", "32 boulevard Voltaire, Marseille", 17.5, 18.0},
        {"Bernard", "Sophie", "48 rue de la République, Lille", 13.0, 14.0},
        {"Petit", "Maxime", "7 place du Marché, Bordeaux", 15.0, 13.5}
    };

    // Affichage
    printf("--- Liste des étudiant·e·s ---\n\n");
    for (int i = 0; i < TAILLE; i++) {
        printf("Étudiant %d\n", i + 1);
        printf("Nom : %s\n", etudiants[i].nom);
        printf("Prénom : %s\n", etudiants[i].prenom);
        printf("Adresse : %s\n", etudiants[i].adresse);
        printf("Note Programmation en C : %.2f\n", etudiants[i].note_prog_c);
        printf("Note Système d'exploitation : %.2f\n", etudiants[i].note_sys_exp);
        printf("\n");
    }

    return 0;

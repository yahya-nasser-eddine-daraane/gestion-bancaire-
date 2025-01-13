#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FICHIER_CLIENTS "clients.csv"
#define FICHIER_TRANSACTIONS "transactions.csv"
#include "recherche.h"
#include "client.h"

void menu_recherche() {
    int choix;
    do {
        printf("\n===== Menu Recherche  =====\n");
        printf("1. Rechercher un compte par nom\n");
        printf("2. Rechercher un compte par numero\n");
        printf("3. Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                rechercher_par_nom();
                break;
            case 2:
                rechercher_par_numero();
                break;
            case 3:
                printf("Retour au menu principal.\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 3);
}

void rechercher_par_nom() {
    char nom_recherche[50];
    printf("Entrez le nom a rechercher : ");
    scanf("%49s", nom_recherche);  // Limite la longueur du nom pour eviter les depassements.

    FILE* fichier = fopen(FICHIER_CLIENTS,"r");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier %s.\n", FICHIER_CLIENTS);
        return;
    }

    Compte client;
    int trouve = 0;
    while (fscanf(fichier, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%lf,%d\n",
                  client.numero_compte, client.nom, client.prenom, client.adresse,
                  client.email, client.telephone, &client.solde, &client.statut) != EOF) {
        if (strcmp(client.nom, nom_recherche) == 0) {
            printf("Compte trouve : %s | %s %s | Solde : %.2f\n",
                   client.numero_compte, client.nom, client.prenom, client.solde);
            trouve = 1;
        }
    }
    fclose(fichier);

    if (!trouve) {
        printf("Aucun compte trouve pour le nom : %s\n", nom_recherche);
    }
}


void rechercher_par_numero() {
    char numero_recherche[20];
    printf("Entrez le numero de compte a rechercher : ");
    scanf("%s", numero_recherche);

    FILE* fichier = fopen(FICHIER_CLIENTS, "r");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    Compte client;
    int trouve = 0;
    while (fscanf(fichier, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%lf,%d\n",
                  client.numero_compte, client.nom, client.prenom, client.adresse,
                  client.email, client.telephone, &client.solde, &client.statut) != EOF) {
        if (strcmp(client.numero_compte, numero_recherche) == 0) {
            printf("Compte trouve : %s | %s %s | Solde : %.2f\n",
                   client.numero_compte, client.nom, client.prenom, client.solde);
            trouve = 1;
        }
    }
    fclose(fichier);

    if (!trouve) {
        printf("Aucun compte trouve pour le numero : %s\n", numero_recherche);
    }
}

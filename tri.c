#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FICHIER_CLIENTS "clients.csv"
#define FICHIER_TRANSACTIONS "transactions.csv"
#include "tri.h"
#include "client.h"


void trier_par_nom() {
    Compte clients[100];
    int nb_clients = 0;

    FILE* fichier = fopen(FICHIER_CLIENTS, "r");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    // Charger les comptes
    while (fscanf(fichier, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%lf,%d\n",
                  clients[nb_clients].numero_compte, clients[nb_clients].nom, clients[nb_clients].prenom,
                  clients[nb_clients].adresse, clients[nb_clients].email, clients[nb_clients].telephone,
                  &clients[nb_clients].solde, &clients[nb_clients].statut) != EOF) {
        nb_clients++;
    }
    fclose(fichier);

    // Tri par nom
    for (int i = 0; i < nb_clients - 1; i++) {
        for (int j = 0; j < nb_clients - i - 1; j++) {
            if (strcmp(clients[j].nom, clients[j + 1].nom) > 0) {
                Compte temp = clients[j];
                clients[j] = clients[j + 1];
                clients[j + 1] = temp;
            }
        }
    }

    // Afficher les comptes tries
    printf("===== Comptes tries par nom =====\n");
    for (int i = 0; i < nb_clients; i++) {
        printf("%s | %s %s | Solde : %.2f\n", clients[i].numero_compte,
               clients[i].nom, clients[i].prenom, clients[i].solde);
    }
}
void menu_tri() {
    int choix;
    do {
        printf("\n===== Menu Tri =====\n");
        printf("1. Trier les comptes par nom\n");
        printf("2. Trier les comptes par solde\n");
        printf("3. Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                trier_par_nom();
                break;
            case 2:
                trier_par_solde();
                break;
            case 3:
                printf("Retour au menu principal.\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 3);
}
void trier_par_solde() {
    Compte clients[100];
    int nb_clients = 0;

    FILE* fichier = fopen(FICHIER_CLIENTS, "r");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    // Charger les comptes
    while (fscanf(fichier, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%lf,%d\n",
                  clients[nb_clients].numero_compte, clients[nb_clients].nom, clients[nb_clients].prenom,
                  clients[nb_clients].adresse, clients[nb_clients].email, clients[nb_clients].telephone,
                  &clients[nb_clients].solde, &clients[nb_clients].statut) != EOF) {
        nb_clients++;
    }
    fclose(fichier);

    // Tri par solde
    for (int i = 0; i < nb_clients - 1; i++) {
        for (int j = 0; j < nb_clients - i - 1; j++) {
            if (clients[j].solde > clients[j + 1].solde) {
                Compte temp = clients[j];
                clients[j] = clients[j + 1];
                clients[j + 1] = temp;
            }
        }
    }

    printf("===== Comptes tries par solde =====\n");
    for (int i = 0; i < nb_clients; i++) {
        printf("%s | %s %s | Solde : %.2f\n", clients[i].numero_compte,
               clients[i].nom, clients[i].prenom, clients[i].solde);
    }
}

#include <stdio.h>
#include "client.h"
#include <stdlib.h>
#include <string.h>
#define FICHIER_CLIENTS "clients.csv"
#define FICHIER_TRANSACTIONS "transactions.csv"

void enregistrer_client() {
    Compte client;
    FILE* fichier = fopen(FICHIER_CLIENTS, "a");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    printf("Entrer le numero de compte : ");
    scanf("%s", client.numero_compte);
    printf("Entrer le nom : ");
    scanf("%s", client.nom);
    printf("Entrer le prenom : ");
    scanf("%s", client.prenom);
    printf("Entrer l'adresse : ");
    scanf(" %[^\n]", client.adresse);
    printf("Entrer l'email : ");
    scanf("%s", client.email);
    printf("Entrer le telephone : ");
    scanf("%s", client.telephone);
    client.solde = 0.0;
    client.statut = 1; // Actif

    fprintf(fichier, "%s,%s,%s,%s,%s,%s,%.2f,%d\n",
            client.numero_compte, client.nom, client.prenom, client.adresse,
            client.email, client.telephone, client.solde, client.statut);

    fclose(fichier);
    printf("Compte enregistrer avec succes.\n");
}

void afficher_comptes() {
    FILE* fichier = fopen(FICHIER_CLIENTS, "r");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    Compte client;
    printf("===== Liste des Comptes =====\n");
    printf("Numero de Compte | Nom | Prenom | Solde | Statut\n");
    while (fscanf(fichier, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%lf,%d\n",
                  client.numero_compte, client.nom, client.prenom, client.adresse,
                  client.email, client.telephone, &client.solde, &client.statut) != EOF) {
        printf("%s | %s | %s | %.2f | %s\n",
               client.numero_compte, client.nom, client.prenom, client.solde,
               client.statut ? "Actif" : "Inactif");
    }

    fclose(fichier);
}

void menu_gestion_clients() {
    int choix;
    do {
        printf("\n===== Gestion des Comptes =====\n");
        printf("1. Ajouter un compte\n");
        printf("2. Afficher les comptes\n");
        printf("3. Retour au menu principal\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                enregistrer_client();
                break;
            case 2:
                afficher_comptes();
                break;
            case 3:
                printf("Retour au menu principal.\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }

    } while (choix != 3);
}

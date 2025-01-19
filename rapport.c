#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FICHIER_CLIENTS "clients.csv"
#define FICHIER_TRANSACTIONS "transactions.csv"
#include "rapport.h"
#include "client.h"


void menu_rapports() {
    int choix;
    do {
        printf("\n===== Menu Rapports =====\n");
        printf("1. Afficher le total des fonds disponibles\n");
        printf("2. Afficher l'historique des transactions d'un compte\n");
        printf("3. Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                afficher_total_fonds();
                break;
            case 2: {
                char numero_compte[20];
                printf("Entrez le numero de compte : ");
                scanf("%s", numero_compte);
                afficher_historique_transactions(numero_compte);
                break;
            }
            case 3:
                printf("Retour au menu principal.\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 3);
}

// Total des fonds
void afficher_total_fonds() {
    FILE* fichier = fopen(FICHIER_CLIENTS, "r");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    Compte client;
    float total_fonds = 0;

    while (fscanf(fichier, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%f,%d\n",
                  client.numero_compte, client.nom, client.prenom, client.adresse,
                  client.email, client.telephone, &client.solde, &client.statut) != EOF) {
        total_fonds += client.solde;
    }

    fclose(fichier);
    printf("Total des fonds disponibles dans la banque : %.2f\n", total_fonds);
}

void afficher_historique_transactions(char* numero_compte) {
    FILE* fichier = fopen(FICHIER_TRANSACTIONS, "r");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    char compte[20], type[50], date[20];
    float montant;
    int trouve = 0;

    printf("===== Historique des Transactions pour le compte %s =====\n", numero_compte);
    printf("Type de Transaction  | Montant  | Date\n");

    while (fscanf(fichier, "%[^,],%[^,],%f,%[^\n]\n", compte, type, &montant, date) == 4) {
        if (strcmp(compte, numero_compte) == 0) {
            printf("%s | %f | %s\n", type, montant, date);
            trouve = 1;
        }
    }

    fclose(fichier);

    if (!trouve) {
        printf("Aucune transaction trouvee pour le compte : %s\n", numero_compte);
    }
}

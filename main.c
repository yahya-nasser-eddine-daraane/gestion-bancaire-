#include <stdio.h>
#include "client.h"
#include "transaction.h"
#include "recherche.h"
#include "tri.h"
#include "rapport.h"
#include <stdlib.h>
#include <string.h>
#define FICHIER_CLIENTS "clients.csv"
#define FICHIER_TRANSACTIONS "transactions.csv"
int main() {
    int choix;

    do {
        printf("\n===== Menu Principal =====\n");
        printf("1. Gestion des comptes clients\n");
        printf("2. Gestion des transactions\n");
        printf("3. Recherche \n");
        printf("4. tri\n");
        printf("5. Rapports\n");
        printf("6. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                menu_gestion_clients();
                break;
            case 2:
                menu_gestion_transactions();
                break;
            case 3:
                menu_recherche();
                break;
            case 4:
                menu_tri();
                break;
            case 5:
                menu_rapports();
                break;
            case 6:
                printf("Merci d'avoir utilise l'application de gestion bancaire !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 6);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "transaction.h"
#define FICHIER_CLIENTS "clients.csv"
#define FICHIER_TRANSACTIONS "transactions.csv"

void enregistrer_transaction( char numero_compte[50], char type[50], float montant,char D[20]) {
    FILE* fichier = fopen(FICHIER_TRANSACTIONS, "a");
    if (!fichier) {
        printf("Erreur d'ouverture du fichier des transactions.\n");
        return;
    }
    fprintf(fichier,"%s,%s,%.2f,%s\n", numero_compte, type, montant,D);
    fclose(fichier);
}

int mettre_a_jour_solde( char numero_compte[50], float montant) {
    FILE* fichier = fopen(FICHIER_CLIENTS, "r");
    FILE* temp = fopen("temp.csv", "w");
    if (!fichier || !temp) {
        printf("Erreur d'ouverture des fichiers.\n");
        if (fichier) fclose(fichier);
        if (temp) fclose(temp);
        return 0;
    }

    Compte client;
    int trouve = 0;
    int mise_a_jour_reussie = 1;

    while (fscanf(fichier, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%f,%d\n",client.numero_compte, client.nom, client.prenom, client.adresse,client.email, client.telephone, &client.solde, &client.statut) != EOF) {
        if (strcmp(client.numero_compte, numero_compte) == 0) {
            trouve = 1;
  // verifier si le solde est suffisant pour un retrait
            if (client.solde + montant < 0) {
                printf("Solde insuffisant pour le compte : %s\n", numero_compte);
                mise_a_jour_reussie = 0;
            } else {
                client.solde += montant; // Mettre a jour le solde
            }
        }
        // ecrire les donnees mises a jour (ou non) dans le fichier temporaire
        fprintf(temp, "%s,%s,%s,%s,%s,%s,%.2f,%d\n",client.numero_compte, client.nom, client.prenom, client.adresse,client.email, client.telephone, client.solde, client.statut);
    }

    fclose(fichier);
    fclose(temp);

    if (!trouve) {
        printf("Compte introuvable : %s\n", numero_compte);
        mise_a_jour_reussie = 0;
    }

    if (mise_a_jour_reussie) {
        remove(FICHIER_CLIENTS);          // Supprimer l'ancien fichier
        rename("temp.csv", FICHIER_CLIENTS); // Renommer le fichier temporaire
    } else {
        remove("temp.csv"); // Supprimer le fichier temporaire en cas d'echec
    }

    return mise_a_jour_reussie;
}


// Fonction pour effectuer un retrait
void retirer_argent() {
    char numero_compte[20];
    float montant;

    printf("Entrez le numero de compte : ");
    scanf("%s", numero_compte);
    printf("Entrez le montant a retirer : ");
    scanf("%f", &montant);
    char D[20];
    printf("entrer la date aaaa-mm-jj");
    scanf("%s",D);
    if (montant <= 0) {
        printf("Le montant doit etre positif.\n");
        return;
    }

    if (mettre_a_jour_solde(numero_compte, -montant)) {
        enregistrer_transaction(numero_compte, "Retrait", montant,D);
        printf("Retrait de %.2f effectue avec succes pour le compte %s.\n", montant, numero_compte);
    } else {
        printf("Erreur : le compte n'existe pas ou le solde est insuffisant.\n");
    }
}

// Fonction pour effectuer un transfert
void transferer_argent() {
    char compte_source[20], compte_destination[20];
    float montant;

    printf("Entrez le numero de compte source : ");
    scanf("%s", compte_source);
    printf("Entrez le numero de compte destination : ");
    scanf("%s", compte_destination);
    printf("Entrez le montant a transferer : ");
    scanf("%f", &montant);
    char D[20];
    printf("entrer la date aaaa-mm-jj");
    scanf("%s",D);

    if (montant <= 0) {
        printf("Le montant doit etre positif.\n");
        return;
    }

    // Retirer le montant du compte source
    if (!mettre_a_jour_solde(compte_source, -montant)) {
        printf("Erreur : transfert echoue, solde insuffisant ou compte source n'exist pas.\n");
        return;
    }

    if (!mettre_a_jour_solde(compte_destination, montant)) {

        mettre_a_jour_solde(compte_source, montant);
        printf("Erreur : transfert echoue, compte destination n'exist pas.\n");
        return;
    }

    enregistrer_transaction(compte_source, "Transfert-Sortant", montant,D);
    enregistrer_transaction(compte_destination, "Transfert-Entrant", montant,D);

    printf("Transfert de %.2f effectue avec succes de %s a %s.\n", montant, compte_source, compte_destination);
}

void deposer_argent() {
    char numero_compte[20];
    float montant;

    printf("=== Depot d'argent ===\n");
    printf("Entrez le numero du compte : ");
    scanf("%s", numero_compte);

    printf("Entrez le montant a deposer : ");
    scanf("%f", &montant);

    if (montant <= 0) {
        printf("Le montant doit etre superieur a 0.\n");
        return;
    }

    if (mettre_a_jour_solde(numero_compte, montant)) {
        printf("Depot effectue avec succes. Montant depose : %.2f\n", montant);
    } else {
        printf("echec du depot. Veuillez verifier le numero du compte.\n");
    }
}

// Fonction pour acceder au menu des transactions
void menu_gestion_transactions() {
    int choix;

    do {
        printf("\n===== Menu Transactions =====\n");
        printf("1. Effectuer un depot\n");
        printf("2. Effectuer un retrait\n");
        printf("3. Effectuer un transfert\n");
        printf("4. Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                deposer_argent();
                break;
            case 2:
                retirer_argent();
                break;
            case 3:
                transferer_argent();
                break;
            case 4:
                printf("Retour au menu principal.\n");
                break;
            default:
                printf("Choix invalide Veuillez reessayer.\n");
        }
    } while (choix != 4);
}

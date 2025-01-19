#ifndef CLIENTS_H
#define CLIENTS_H

typedef struct {
    char numero_compte[20];
    char nom[50];
    char prenom[50];
    char adresse[100];
    char email[50];
    char telephone[15];
    float solde;
    int statut; // 1 pour actif, 0 pour inactif
} Compte;

void menu_gestion_clients();
void enregistrer_client();
void modifier_client();
void supprimer_client();
void afficher_comptes();
void trier_par_nom();
void trier_par_solde();
void afficher_historique_transactions();
#endif


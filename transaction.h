#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

typedef struct {
    char numero_compte[20];
    char type_transaction[20];
    float montant;
    char date[20];
} Transaction;

void menu_gestion_transactions();
void effectuer_depot();
void effectuer_retrait();
#endif


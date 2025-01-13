# gestion-bancaire-
# Application de Gestion Bancaire

Ce projet est une application de gestion bancaire en langage C, permettant la gestion des comptes clients, des transactions, des recherches, des tris, et la génération de rapports. Elle utilise des fichiers CSV pour stocker les données.

## Fonctionnalités Principales

1. **Gestion des comptes clients :**
   - Ajouter un compte client.
   - Afficher la liste des comptes clients.
   - Modifier ou supprimer un compte client.
   - Trier les comptes par nom ou par solde.

2. **Gestion des transactions :**
   - Effectuer des dépôts.
   - Effectuer des retraits.
   - Transférer de l'argent entre deux comptes.

3. **Recherche :**
   - Rechercher un compte client par nom.
   - Rechercher un compte client par numéro.

4. **Rapports :**
   - Afficher le total des fonds disponibles dans la banque.
   - Consulter l'historique des transactions d'un compte.

## Structure du Projet

Le projet est composé des fichiers suivants :

- **`main.c`** : Point d'entrée de l'application. Contient le menu principal.
- **`client.c`** / **`client.h`** : Gestion des comptes clients.
- **`transaction.c`** / **`transaction.h`** : Gestion des transactions.
- **`recherche.c`** / **`recherche.h`** : Fonctions de recherche.
- **`rapport.c`** / **`rapport.h`** : Génération de rapports.
- **`tri.c`** / **`tri.h`** : Tri des comptes clients.

## Fichiers de Données

- **`clients.csv`** : Fichier CSV pour stocker les informations des comptes clients.
- **`transactions.csv`** : Fichier CSV pour stocker les transactions.

## Fonctionnalités

### Gestion des comptes clients
- **Ajouter un compte** : Ajoute un nouveau client avec des informations telles que le nom, prénom, numéro de compte, adresse, email, téléphone, etc.
- **Afficher les comptes** : Affiche tous les comptes clients enregistrés.
- **Rechercher un compte** :
  - Recherche par nom.
  - Recherche par numéro de compte.

### Gestion des transactions
- **Dépôt** : Permet de déposer de l'argent dans un compte.
- **Retrait** : Permet de retirer de l'argent d'un compte (sous réserve d'un solde suffisant).
- **Transfert** : Permet de transférer des fonds d'un compte à un autre.

### Tri des comptes
- **Par nom** : Trie les comptes clients par ordre alphabétique des noms.
- **Par solde** : Trie les comptes clients par ordre croissant ou décroissant des soldes.

### Rapports
- **Total des fonds disponibles** : Affiche la somme totale des soldes de tous les comptes clients.
- **Historique des transactions** : Affiche les transactions associées à un compte donné.

## Structure du projet

- **`client.c`** : Contient les fonctions liées à la gestion des comptes clients.
- **`client.h`** : Déclare les structures et fonctions liées aux clients.
- **`transaction.c`** : Contient les fonctions pour gérer les dépôts, retraits et transferts.
- **`transaction.h`** : Déclare les structures et fonctions liées aux transactions.
- **`recherche.c`** : Contient les fonctions de recherche des comptes.
- **`recherche.h`** : Déclare les fonctions de recherche.
- **`tri.c`** : Implémente les algorithmes de tri pour les comptes.
- **`tri.h`** : Déclare les fonctions de tri.
- **`rapport.c`** : Implémente les fonctionnalités de génération de rapports.
- **`rapport.h`** : Déclare les fonctions des rapports.
- **`main.c`** : Point d'entrée principal du programme. Contient le menu principal.

## Structure des données

### Client
```c
typedef struct {
    char numero_compte[20];
    char nom[50];
    char prenom[50];
    char adresse[100];
    char email[50];
    char telephone[15];
    double solde;
    int statut; // 1 pour actif, 0 pour inactif
} Compte;
### transaction 
```c
typedef struct {
    int nombre_total_comptes; // Nombre total de comptes actifs
    double total_fonds;       // Total des fonds détenus dans tous les comptes
    int transactions_total;   // Nombre total de transactions effectuées
} StatistiquesGenerales;

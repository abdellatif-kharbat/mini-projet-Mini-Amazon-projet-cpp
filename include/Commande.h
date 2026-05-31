#ifndef COMMANDE_H
#define COMMANDE_H

#include "Panier.h"  // Pour utiliser LignePanier
#include <string>    // Pour utiliser string

using namespace std;

class Commande {
private:
    int numero;                         // Numéro unique de la commande
    vector<LignePanier> produitsCommandes;  // Liste des produits commandés
    double total;                       // Montant total de la commande
    string date;                        // Date de la commande

public:
    // Constructeurs
    Commande();                          // Constructeur par défaut
    Commande(int numero, vector<LignePanier> produits, double total);  // Constructeur avec paramètres

    // Getters
    int getNumero() const;      // Retourne le numéro de commande
    double getTotal() const;    // Retourne le montant total

    // Méthodes
    void afficher() const;      // Affiche les détails de la commande

    // Surcharge de l'opérateur << pour l'affichage
    friend ostream& operator<<(ostream& out, const Commande& c);
};

#endif

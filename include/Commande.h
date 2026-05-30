#ifndef COMMANDE_H
#define COMMANDE_H

#include "Panier.h"
#include <string>

using namespace std;

class Commande {
private:
    int numero;
    vector<LignePanier> produitsCommandes;
    double total;
    string date;

public:
    Commande();
    Commande(int numero, vector<LignePanier> produits, double total);

    int getNumero() const;
    double getTotal() const;
    void afficher() const;

    friend ostream& operator<<(ostream& out, const Commande& c);
};

#endif

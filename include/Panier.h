#ifndef PANIER_H
#define PANIER_H

#include "Produit.h"
#include <vector>

using namespace std;

struct LignePanier {
    Produit* produit;
    int quantite;
};

class Panier {
private:
    vector<LignePanier> lignes;

public:
    void ajouterProduit(Produit* produit, int quantite);
    void afficher() const;
    double calculerTotal() const;
    bool estVide() const;
    vector<LignePanier> getLignes() const;
    void vider();

    Panier& operator+=(Produit* produit);
};

#endif

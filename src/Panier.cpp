#include "Panier.h"

void Panier::ajouterProduit(Produit* produit, int quantite) {
    if (produit == nullptr || quantite <= 0) {
        cout << "Produit ou quantite invalide." << endl;
        return;
    }

    for (int i = 0; i < lignes.size(); i++) {
        if (*(lignes[i].produit) == *produit) {
            lignes[i].quantite += quantite;
            return;
        }
    }

    LignePanier ligne;
    ligne.produit = produit;
    ligne.quantite = quantite;
    lignes.push_back(ligne);
}

void Panier::afficher() const {
    if (lignes.empty()) {
        cout << "Le panier est vide." << endl;
        return;
    }

    cout << "\n--- Panier ---" << endl;
    for (int i = 0; i < lignes.size(); i++) {
        cout << lignes[i].produit->getNom()
             << " x " << lignes[i].quantite
             << " = " << lignes[i].produit->calculerPrixFinal() * lignes[i].quantite
             << " DH" << endl;
    }
    cout << "Total: " << calculerTotal() << " DH" << endl;
}

double Panier::calculerTotal() const {
    double total = 0;
    for (int i = 0; i < lignes.size(); i++) {
        total += lignes[i].produit->calculerPrixFinal() * lignes[i].quantite;
    }
    return total;
}

bool Panier::estVide() const {
    return lignes.empty();
}

vector<LignePanier> Panier::getLignes() const {
    return lignes;
}

void Panier::vider() {
    lignes.clear();
}

Panier& Panier::operator+=(Produit* produit) {
    ajouterProduit(produit, 1);
    return *this;
}

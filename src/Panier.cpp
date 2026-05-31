#include "Panier.h"

// Ajoute un produit au panier
void Panier::ajouterProduit(Produit* produit, int quantite) {
    // Vérifie si le produit et la quantité sont valides
    if (produit == nullptr || quantite <= 0) {
        cout << "Produit ou quantite invalide." << endl;
        return;
    }

    // Vérifie si le produit est déjà dans le panier
    for (int i = 0; i < lignes.size(); i++) {
        if (*(lignes[i].produit) == *produit) {
            // Déjà présent: augmente la quantité
            lignes[i].quantite += quantite;
            return;
        }
    }

    // Nouveau produit: crée une nouvelle ligne
    LignePanier ligne;
    ligne.produit = produit;
    ligne.quantite = quantite;
    lignes.push_back(ligne);
}

// Affiche le contenu du panier
void Panier::afficher() const {
    // Vérifie si panier vide
    if (lignes.empty()) {
        cout << "Le panier est vide." << endl;
        return;
    }

    cout << "\n--- Panier ---" << endl;
    
    // Affiche chaque ligne
    for (int i = 0; i < lignes.size(); i++) {
        cout << lignes[i].produit->getNom()
             << " x " << lignes[i].quantite
             << " = " << lignes[i].produit->calculerPrixFinal() * lignes[i].quantite
             << " DH" << endl;
    }
    
    // Affiche le total
    cout << "Total: " << calculerTotal() << " DH" << endl;
}

// Calcule le total du panier
double Panier::calculerTotal() const {
    double total = 0;
    
    for (int i = 0; i < lignes.size(); i++) {
        total += lignes[i].produit->calculerPrixFinal() * lignes[i].quantite;
    }
    
    return total;
}

// Vérifie si le panier est vide
bool Panier::estVide() const {
    return lignes.empty();
}

// Retourne les lignes du panier (copie)
vector<LignePanier> Panier::getLignes() const {
    return lignes;
}

// Vide le panier
void Panier::vider() {
    lignes.clear();
}

// Opérateur += pour ajouter un produit (quantité 1)
Panier& Panier::operator+=(Produit* produit) {
    ajouterProduit(produit, 1);
    return *this;
}

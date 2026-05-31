#ifndef PANIER_H
#define PANIER_H

#include "Produit.h"  // Pour utiliser la classe Produit
#include <vector>     // Pour utiliser vector

using namespace std;

// Structure représentant une ligne dans le panier
struct LignePanier {
    Produit* produit;   // Pointeur vers le produit
    int quantite;       // Quantité commandée
};

class Panier {
private:
    vector<LignePanier> lignes;  // Liste des produits dans le panier

public:
    // Ajoute un produit au panier avec une quantité
    void ajouterProduit(Produit* produit, int quantite);
    
    // Affiche le contenu du panier
    void afficher() const;
    
    // Calcule le montant total du panier
    double calculerTotal() const;
    
    // Vérifie si le panier est vide
    bool estVide() const;
    
    // Retourne la liste des lignes du panier
    vector<LignePanier> getLignes() const;
    
    // Vide complètement le panier
    void vider();
    
    // Opérateur += pour ajouter un produit (ajoute 1 exemplaire)
    Panier& operator+=(Produit* produit);
};

#endif

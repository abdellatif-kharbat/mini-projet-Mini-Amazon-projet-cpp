#ifndef PRODUIT_H
#define PRODUIT_H

#include <iostream>
#include <string>

using namespace std;

// Classe de base pour tous les produits
class Produit {
protected:
    int id;           // Identifiant du produit
    string nom;       // Nom du produit
    double prix;      // Prix unitaire HT
    int stock;        // Quantité en stock

public:
    // Constructeurs
    Produit();                                                // Constructeur par défaut
    Produit(int id, string nom, double prix, int stock);     // Constructeur avec paramètres
    virtual ~Produit();  // Destructeur virtuel

    // Getters
    int getId() const;           // Retourne l'ID
    string getNom() const;       // Retourne le nom
    double getPrix() const;      // Retourne le prix
    int getStock() const;        // Retourne le stock

    // Setters
    void setStock(int stock);              // Modifie le stock
    void diminuerStock(int quantite);      // Diminue le stock

    // Méthodes virtuelles (peuvent être redéfinies)
    virtual string getType() const;              // Retourne le type de produit
    virtual double calculerPrixFinal() const;    // Calcule le prix TTC

    // Surcharge des opérateurs
    bool operator==(const Produit& p) const;  // Compare deux produits par ID
    bool operator<(const Produit& p) const;   // Compare deux produits par prix

    friend ostream& operator<<(ostream& out, const Produit& p);  // Affiche un produit
};

// Classe pour les produits électroniques
class ProduitElectronique : public Produit {
private:
    int garantie;  // Durée de garantie en mois

public:
    ProduitElectronique(int id, string nom, double prix, int stock, int garantie);
    string getType() const override;              // Type = "Electronique"
    double calculerPrixFinal() const override;    // Prix = (prix - 5%) + TVA 20%
};

// Classe pour les produits alimentaires
class ProduitAlimentaire : public Produit {
private:
    string dateExpiration;  // Date limite de consommation

public:
    ProduitAlimentaire(int id, string nom, double prix, int stock, string dateExpiration);
    string getType() const override;              // Type = "Alimentaire"
    double calculerPrixFinal() const override;    // Prix = prix + TVA 7%
};

// Classe pour les vêtements
class Vetement : public Produit {
private:
    string taille;  // Taille du vêtement (S, M, L, XL)

public:
    Vetement(int id, string nom, double prix, int stock, string taille);
    string getType() const override;              // Type = "Vetement"
    double calculerPrixFinal() const override;    // Prix = (prix - 10%) + TVA 20%
};

#endif

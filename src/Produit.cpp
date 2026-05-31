#include "Produit.h"

// ========== CLASSE PRODUIT ==========

// Constructeur par défaut
Produit::Produit() {
    id = 0;
    nom = "";
    prix = 0;
    stock = 0;
}

// Constructeur avec paramètres
Produit::Produit(int id, string nom, double prix, int stock) {
    this->id = id;
    this->nom = nom;
    this->prix = prix;
    this->stock = stock;
}

// Destructeur
Produit::~Produit() {
}

// Getters
int Produit::getId() const {
    return id;
}

string Produit::getNom() const {
    return nom;
}

double Produit::getPrix() const {
    return prix;
}

int Produit::getStock() const {
    return stock;
}

// Modifie le stock
void Produit::setStock(int stock) {
    this->stock = stock;
}

// Diminue le stock (si assez disponible)
void Produit::diminuerStock(int quantite) {
    if (quantite <= stock) {
        stock -= quantite;
    }
}

// Retourne le type (par défaut)
string Produit::getType() const {
    return "Produit";
}

// Calcule le prix final (par défaut: TVA 20%)
double Produit::calculerPrixFinal() const {
    return prix * 1.20;
}

// Compare par ID
bool Produit::operator==(const Produit& p) const {
    return id == p.id;
}

// Compare par prix
bool Produit::operator<(const Produit& p) const {
    return prix < p.prix;
}

// Affiche un produit
ostream& operator<<(ostream& out, const Produit& p) {
    out << "ID: " << p.id << " | Nom: " << p.nom
        << " | Type: " << p.getType()
        << " | Prix: " << p.prix
        << " | Prix avec TVA/remise: " << p.calculerPrixFinal()
        << " | Stock: " << p.stock;
    return out;
}

// ========== PRODUIT ELECTRONIQUE ==========

// Constructeur
ProduitElectronique::ProduitElectronique(int id, string nom, double prix, int stock, int garantie)
    : Produit(id, nom, prix, stock) {
    this->garantie = garantie;
}

// Type = Electronique
string ProduitElectronique::getType() const {
    return "Electronique";
}

// Prix = (prix - 5%) + TVA 20%
double ProduitElectronique::calculerPrixFinal() const {
    double prixRemise = prix - (prix * 0.05);
    return prixRemise * 1.20;
}

// ========== PRODUIT ALIMENTAIRE ==========

// Constructeur
ProduitAlimentaire::ProduitAlimentaire(int id, string nom, double prix, int stock, string dateExpiration)
    : Produit(id, nom, prix, stock) {
    this->dateExpiration = dateExpiration;
}

// Type = Alimentaire
string ProduitAlimentaire::getType() const {
    return "Alimentaire";
}

// Prix = prix + TVA 7%
double ProduitAlimentaire::calculerPrixFinal() const {
    return prix * 1.07;
}

// ========== VETEMENT ==========

// Constructeur
Vetement::Vetement(int id, string nom, double prix, int stock, string taille)
    : Produit(id, nom, prix, stock) {
    this->taille = taille;
}

// Type = Vetement
string Vetement::getType() const {
    return "Vetement";
}

// Prix = (prix - 10%) + TVA 20%
double Vetement::calculerPrixFinal() const {
    double prixRemise = prix - (prix * 0.10);
    return prixRemise * 1.20;
}

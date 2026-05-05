#include "Produit.h"

Produit::Produit() {
    id = 0;
    nom = "";
    prix = 0;
    stock = 0;
}

Produit::Produit(int id, string nom, double prix, int stock) {
    this->id = id;
    this->nom = nom;
    this->prix = prix;
    this->stock = stock;
}

Produit::~Produit() {
}

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

void Produit::setStock(int stock) {
    this->stock = stock;
}

void Produit::diminuerStock(int quantite) {
    if (quantite <= stock) {
        stock -= quantite;
    }
}

string Produit::getType() const {
    return "Produit";
}

double Produit::calculerPrixFinal() const {
    return prix * 1.20; // TVA 20%
}

bool Produit::operator==(const Produit& p) const {
    return id == p.id;
}

bool Produit::operator<(const Produit& p) const {
    return prix < p.prix;
}

ostream& operator<<(ostream& out, const Produit& p) {
    out << "ID: " << p.id << " | Nom: " << p.nom
        << " | Type: " << p.getType()
        << " | Prix: " << p.prix
        << " | Prix avec TVA/remise: " << p.calculerPrixFinal()
        << " | Stock: " << p.stock;
    return out;
}

ProduitElectronique::ProduitElectronique(int id, string nom, double prix, int stock, int garantie)
    : Produit(id, nom, prix, stock) {
    this->garantie = garantie;
}

string ProduitElectronique::getType() const {
    return "Electronique";
}

double ProduitElectronique::calculerPrixFinal() const {
    double prixRemise = prix - (prix * 0.05); // 5% remise
    return prixRemise * 1.20;
}

ProduitAlimentaire::ProduitAlimentaire(int id, string nom, double prix, int stock, string dateExpiration)
    : Produit(id, nom, prix, stock) {
    this->dateExpiration = dateExpiration;
}

string ProduitAlimentaire::getType() const {
    return "Alimentaire";
}

double ProduitAlimentaire::calculerPrixFinal() const {
    return prix * 1.07; // TVA 7%
}

Vetement::Vetement(int id, string nom, double prix, int stock, string taille)
    : Produit(id, nom, prix, stock) {
    this->taille = taille;
}

string Vetement::getType() const {
    return "Vetement";
}

double Vetement::calculerPrixFinal() const {
    double prixRemise = prix - (prix * 0.10); // 10% remise
    return prixRemise * 1.20;
}

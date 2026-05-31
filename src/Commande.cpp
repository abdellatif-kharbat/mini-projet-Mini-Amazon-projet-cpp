#include "Commande.h"

// ========== CONSTRUCTEURS ==========

// Constructeur par défaut
Commande::Commande() {
    numero = 0;
    total = 0;
    date = "Non definie";
}

// Constructeur avec paramètres
Commande::Commande(int numero, vector<LignePanier> produits, double total) {
    this->numero = numero;
    this->produitsCommandes = produits;
    this->total = total;
    this->date = "Aujourd'hui";
}

// ========== GETTERS ==========

// Retourne le numéro de commande
int Commande::getNumero() const {
    return numero;
}

// Retourne le montant total
double Commande::getTotal() const {
    return total;
}

// ========== AFFICHAGE ==========

// Affiche la commande
void Commande::afficher() const {
    cout << *this;
}

// ========== SURCHARGE OPERATEUR ==========

// Opérateur << pour afficher une commande
ostream& operator<<(ostream& out, const Commande& c) {
    out << "\nCommande numero: " << c.numero << endl;
    out << "Date: " << c.date << endl;
    out << "Produits:" << endl;

    // Affiche chaque produit commandé
    for (int i = 0; i < c.produitsCommandes.size(); i++) {
        out << "- " << c.produitsCommandes[i].produit->getNom()
            << " x " << c.produitsCommandes[i].quantite << endl;
    }

    out << "Total: " << c.total << " DH" << endl;
    
    return out;
}

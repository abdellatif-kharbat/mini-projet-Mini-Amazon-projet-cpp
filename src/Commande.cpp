#include "Commande.h"

Commande::Commande() {
    numero = 0;
    total = 0;
    date = "Non definie";
}

Commande::Commande(int numero, vector<LignePanier> produits, double total) {
    this->numero = numero;
    this->produitsCommandes = produits;
    this->total = total;
    this->date = "Aujourd'hui";
}

int Commande::getNumero() const {
    return numero;
}

double Commande::getTotal() const {
    return total;
}

void Commande::afficher() const {
    cout << *this;
}

ostream& operator<<(ostream& out, const Commande& c) {
    out << "\nCommande numero: " << c.numero << endl;
    out << "Date: " << c.date << endl;
    out << "Produits:" << endl;

    for (int i = 0; i < c.produitsCommandes.size(); i++) {
        out << "- " << c.produitsCommandes[i].produit->getNom()
            << " x " << c.produitsCommandes[i].quantite << endl;
    }

    out << "Total: " << c.total << " DH" << endl;
    return out;
}

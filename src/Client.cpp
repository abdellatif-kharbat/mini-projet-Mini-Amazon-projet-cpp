#include "Client.h"

Client::Client() {
    id = 0;
    nom = "";
    email = "";
}

Client::Client(int id, string nom, string email) {
    this->id = id;
    this->nom = nom;
    this->email = email;
}

int Client::getId() const {
    return id;
}

string Client::getNom() const {
    return nom;
}

void Client::ajouterCommande(Commande commande) {
    historique.push_back(commande);
}

void Client::afficherHistorique() const {
    cout << "\n--- Historique de " << nom << " ---" << endl;
    if (historique.empty()) {
        cout << "Aucune commande." << endl;
        return;
    }

    for (int i = 0; i < historique.size(); i++) {
        cout << historique[i] << endl;
    }
}

ostream& operator<<(ostream& out, const Client& c) {
    out << "Client: " << c.nom << " | Email: " << c.email;
    return out;
}

#include "Client.h"

// ========== CONSTRUCTEURS ==========

// Constructeur par défaut
Client::Client() {
    id = 0;
    nom = "";
    email = "";
}

// Constructeur avec paramètres
Client::Client(int id, string nom, string email) {
    this->id = id;
    this->nom = nom;
    this->email = email;
}

// ========== GETTERS ==========

// Retourne l'ID du client
int Client::getId() const {
    return id;
}

// Retourne le nom du client
string Client::getNom() const {
    return nom;
}

// ========== GESTION DE L'HISTORIQUE ==========

// Ajoute une commande à l'historique
void Client::ajouterCommande(Commande commande) {
    historique.push_back(commande);
}

// Affiche tout l'historique des commandes
void Client::afficherHistorique() const {
    cout << "\n--- Historique de " << nom << " ---" << endl;
    
    // Vérifie si le client a des commandes
    if (historique.empty()) {
        cout << "Aucune commande." << endl;
        return;
    }

    // Affiche chaque commande
    for (int i = 0; i < historique.size(); i++) {
        cout << historique[i] << endl;
    }
}

// ========== SURCHARGE OPERATEUR ==========

// Opérateur << pour afficher un client
ostream& operator<<(ostream& out, const Client& c) {
    out << "Client: " << c.nom << " | Email: " << c.email;
    return out;
}

#ifndef CLIENT_H
#define CLIENT_H

#include "Commande.h"
#include <vector>

using namespace std;

class Client {
private:
    int id;                      // Identifiant du client
    string nom;                  // Nom du client
    string email;                // Email du client
    vector<Commande> historique; // Liste des commandes du client

public:
    // Constructeurs
    Client();                                    // Constructeur par défaut
    Client(int id, string nom, string email);    // Constructeur avec paramètres

    // Getters
    int getId() const;          // Retourne l'ID du client
    string getNom() const;      // Retourne le nom du client

    // Méthodes
    void ajouterCommande(Commande commande);  // Ajoute une commande à l'historique
    void afficherHistorique() const;          // Affiche toutes les commandes du client

    // Surcharge de l'opérateur << pour l'affichage
    friend ostream& operator<<(ostream& out, const Client& c);
};

#endif

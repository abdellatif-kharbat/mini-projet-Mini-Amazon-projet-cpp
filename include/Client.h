#ifndef CLIENT_H
#define CLIENT_H

#include "Commande.h"
#include <vector>

using namespace std;

class Client {
private:
    int id;
    string nom;
    string email;
    vector<Commande> historique;

public:
    Client();
    Client(int id, string nom, string email);

    int getId() const;
    string getNom() const;

    void ajouterCommande(Commande commande);
    void afficherHistorique() const;

    friend ostream& operator<<(ostream& out, const Client& c);
};

#endif

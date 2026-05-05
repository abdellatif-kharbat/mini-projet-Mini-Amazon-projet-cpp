#include "Client.h"
#include "Produit.h"
#include "Panier.h"

#include <iostream>
#include <vector>

using namespace std;

void afficherCatalogue(vector<Produit*>& produits) {
    cout << "\n--- Catalogue des produits ---" << endl;
    for (int i = 0; i < produits.size(); i++) {
        cout << *produits[i] << endl;
        if (produits[i]->getStock() <= 2) {
            cout << "  Attention: stock presque termine!" << endl;
        }
    }
}

Produit* chercherProduit(vector<Produit*>& produits, int id) {
    for (int i = 0; i < produits.size(); i++) {
        if (produits[i]->getId() == id) {
            return produits[i];
        }
    }
    return nullptr;
}

bool verifierStock(Panier& panier) {
    vector<LignePanier> lignes = panier.getLignes();
    for (int i = 0; i < lignes.size(); i++) {
        if (lignes[i].quantite > lignes[i].produit->getStock()) {
            cout << "Stock insuffisant pour " << lignes[i].produit->getNom() << endl;
            return false;
        }
    }
    return true;
}

void validerCommande(Client& client, Panier& panier, int& numeroCommande) {
    if (panier.estVide()) {
        cout << "Panier vide, impossible de commander." << endl;
        return;
    }

    if (!verifierStock(panier)) {
        return;
    }

    vector<LignePanier> lignes = panier.getLignes();
    for (int i = 0; i < lignes.size(); i++) {
        lignes[i].produit->diminuerStock(lignes[i].quantite);
    }

    Commande commande(numeroCommande, lignes, panier.calculerTotal());
    client.ajouterCommande(commande);
    numeroCommande++;

    panier.vider();
    cout << "Commande validee avec succes." << endl;
}

int main() {
    vector<Produit*> produits;
    produits.push_back(new ProduitElectronique(1, "Smartphone Samsung", 3200, 5, 24));
    produits.push_back(new ProduitElectronique(2, "Casque Bluetooth", 350, 2, 12));
    produits.push_back(new ProduitAlimentaire(3, "Cafe", 45, 10, "12/2026"));
    produits.push_back(new Vetement(4, "T-shirt", 120, 7, "M"));

    Client client(1, "Yassine", "yassine@gmail.com");
    Panier panier;
    int choix;
    int numeroCommande = 1;

    do {
        cout << "\n===== MINI AMAZON =====" << endl;
        cout << "1. Afficher catalogue" << endl;
        cout << "2. Ajouter produit au panier" << endl;
        cout << "3. Afficher panier" << endl;
        cout << "4. Valider commande" << endl;
        cout << "5. Historique client" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix: ";
        cin >> choix;

        if (choix == 1) {
            afficherCatalogue(produits);
        } else if (choix == 2) {
            int id, qte;
            cout << "Donner ID du produit: ";
            cin >> id;
            cout << "Donner quantite: ";
            cin >> qte;

            Produit* p = chercherProduit(produits, id);
            if (p != nullptr) {
                panier.ajouterProduit(p, qte);
                cout << "Produit ajoute au panier." << endl;
            } else {
                cout << "Produit introuvable." << endl;
            }
        } else if (choix == 3) {
            panier.afficher();
        } else if (choix == 4) {
            validerCommande(client, panier, numeroCommande);
        } else if (choix == 5) {
            client.afficherHistorique();
        } else if (choix != 0) {
            cout << "Choix incorrect." << endl;
        }

    } while (choix != 0);

    for (int i = 0; i < produits.size(); i++) {
        delete produits[i];
    }

    cout << "Fin du programme." << endl;
    return 0;
}

#include "Client.h"
#include "Produit.h"
#include "Panier.h"

#include <iostream>
#include <vector>

using namespace std;

/**
 * Affiche la liste complète des produits disponibles
 * @param produits Vecteur contenant les pointeurs vers les produits
 */
void afficherCatalogue(vector<Produit*>& produits) {
    cout << "\n--- Catalogue des produits ---" << endl;
    // Parcours de tous les produits du catalogue
    for (int i = 0; i < produits.size(); i++) {
        cout << *produits[i] << endl;  // Affiche les détails du produit via l'opérateur <<
        // Avertissement si le stock est faible (<= 2 unités)
        if (produits[i]->getStock() <= 2) {
            cout << "  Attention: stock presque termine!" << endl;
        }
    }
}

/**
 * Recherche un produit par son identifiant
 * @param produits Vecteur des produits
 * @param id Identifiant du produit recherché
 * @return Pointeur vers le produit trouvé, nullptr sinon
 */
Produit* chercherProduit(vector<Produit*>& produits, int id) {
    // Parcours linéaire du catalogue
    for (int i = 0; i < produits.size(); i++) {
        if (produits[i]->getId() == id) {
            return produits[i];  // Produit trouvé
        }
    }
    return nullptr;  // Produit non trouvé
}

/**
 * Vérifie si la quantité demandée pour chaque produit est disponible en stock
 * @param panier Panier contenant les produits à vérifier
 * @return true si tout est en stock, false sinon
 */
bool verifierStock(Panier& panier) {
    vector<LignePanier> lignes = panier.getLignes();  // Récupère les lignes du panier
    // Vérifie chaque produit du panier
    for (int i = 0; i < lignes.size(); i++) {
        if (lignes[i].quantite > lignes[i].produit->getStock()) {
            cout << "Stock insuffisant pour " << lignes[i].produit->getNom() << endl;
            return false;  // Stock insuffisant
        }
    }
    return true;  // Tout est disponible
}

/**
 * Valide la commande du client : vérifie le stock, diminue les quantités, 
 * crée la commande et l'ajoute à l'historique du client
 * @param client Référence vers le client qui passe commande
 * @param panier Référence vers le panier à valider
 * @param numeroCommande Référence vers le numéro de commande (incrémenté automatiquement)
 */
void validerCommande(Client& client, Panier& panier, int& numeroCommande) {
    // Vérifie si le panier n'est pas vide
    if (panier.estVide()) {
        cout << "Panier vide, impossible de commander." << endl;
        return;
    }

    // Vérifie la disponibilité des stocks
    if (!verifierStock(panier)) {
        return;
    }

    // Diminue les stocks des produits commandés
    vector<LignePanier> lignes = panier.getLignes();
    for (int i = 0; i < lignes.size(); i++) {
        lignes[i].produit->diminuerStock(lignes[i].quantite);
    }

    // Crée la commande et l'ajoute à l'historique du client
    Commande commande(numeroCommande, lignes, panier.calculerTotal());
    client.ajouterCommande(commande);
    numeroCommande++;  // Incrémente pour la prochaine commande

    // Vide le panier après validation
    panier.vider();
    cout << "Commande validee avec succes." << endl;
}

/**
 * Programme principal : point d'entrée de l'application
 */
int main() {
    // ========== INITIALISATION DES DONNEES ==========
    vector<Produit*> produits;  // Catalogue des produits (polymorphisme)
    
    // Création des produits avec différents types
    produits.push_back(new ProduitElectronique(1, "Smartphone Samsung", 3200, 5, 24));   // TVA 20% + garantie 24 mois
    produits.push_back(new ProduitElectronique(2, "Casque Bluetooth", 350, 2, 12));       // Stock faible (alerte)
    produits.push_back(new ProduitAlimentaire(3, "Cafe", 45, 10, "12/2026"));             // TVA 7% + date d'expiration
    produits.push_back(new Vetement(4, "T-shirt", 120, 7, "M"));                          // TVA 10% + taille

    Client client(1, "Yassine", "yassine@gmail.com");  // Création du client
    Panier panier;                                      // Panier du client
    int choix;                                          // Choix du menu
    int numeroCommande = 1;                             // Compteur de commandes

    // ========== BOUCLE PRINCIPALE DU MENU ==========
    do {
        // Affichage du menu principal
        cout << "\n===== MINI AMAZON =====" << endl;
        cout << "1. Afficher catalogue" << endl;
        cout << "2. Ajouter produit au panier" << endl;
        cout << "3. Afficher panier" << endl;
        cout << "4. Valider commande" << endl;
        cout << "5. Historique client" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix: ";
        cin >> choix;

        // ========== TRAITEMENT DES CHOIX ==========
        if (choix == 1) {
            // Affiche tous les produits disponibles
            afficherCatalogue(produits);
            
        } else if (choix == 2) {
            // Ajout d'un produit au panier
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
            // Affiche le contenu du panier
            panier.afficher();
            
        } else if (choix == 4) {
            // Valide la commande
            validerCommande(client, panier, numeroCommande);
            
        } else if (choix == 5) {
            // Affiche l'historique des commandes du client
            client.afficherHistorique();
            
        } else if (choix != 0) {
            // Gestion des choix invalides
            cout << "Choix incorrect." << endl;
        }

    } while (choix != 0);  // Continue tant que l'utilisateur ne quitte pas

    // ========== NETTOYAGE DE LA MEMOIRE ==========
    // Libération de la mémoire allouée dynamiquement pour les produits
    for (int i = 0; i < produits.size(); i++) {
        delete produits[i];
    }

    cout << "Fin du programme." << endl;
    return 0;  // Fin du programme
}

#include "Commande.h"

// ==================== CONSTRUCTEURS ====================

/**
 * Constructeur par défaut - Crée une commande vide
 * Utilisé lors de l'initialisation ou pour des cas d'erreur
 */
Commande::Commande() {
    numero = 0;               // Numéro de commande nul (invalide)
    total = 0;                // Montant total à zéro
    date = "Non definie";     // Date non spécifiée
}

/**
 * Constructeur paramétré - Crée une commande complète après validation
 * @param numero Numéro unique de la commande (incrémenté automatiquement par main)
 * @param produits Vecteur contenant toutes les lignes de produits commandés
 * @param total Montant total TTC de la commande
 * 
 * Note: La date est automatiquement définie à "Aujourd'hui"
 * (Version simplifiée - en production, on utiliserait une vraie date système)
 */
Commande::Commande(int numero, vector<LignePanier> produits, double total) {
    this->numero = numero;
    this->produitsCommandes = produits;  // Copie des lignes du panier vers la commande
    this->total = total;
    this->date = "Aujourd'hui";          // Date de la commande (moment de validation)
}

// ==================== GETTERS ====================

/**
 * Récupère le numéro unique de la commande
 * @return Numéro de commande (entier positif unique)
 */
int Commande::getNumero() const {
    return numero;
}

/**
 * Récupère le montant total de la commande (TTC)
 * @return Montant total en dirhams (DH)
 */
double Commande::getTotal() const {
    return total;
}

// ==================== METHODES D'AFFICHAGE ====================

/**
 * Affiche les détails complets de la commande
 * Utilise l'opérateur << surchargé pour un affichage cohérent
 * 
 * Contenu affiché:
 * - Numéro de commande
 * - Date de commande
 * - Liste des produits avec quantités
 * - Montant total
 */
void Commande::afficher() const {
    cout << *this;  // Délègue l'affichage à l'opérateur << surchargé
}

// ==================== SURCHARGE DES OPERATEURS ====================

/**
 * Surcharge de l'opérateur << pour l'affichage d'une commande
 * Permet d'écrire directement: cout << commande;
 * 
 * @param out Flux de sortie (généralement cout)
 * @param c Commande à afficher (constante - ne modifie pas l'objet)
 * @return Référence vers le flux de sortie (pour chaînage)
 * 
 * Format d'affichage:
 * Commande numero: X
 * Date: JJ/MM/AAAA
 * Produits:
 * - NomProduit x Quantite
 * Total: XXX DH
 */
ostream& operator<<(ostream& out, const Commande& c) {
    // En-tête de la commande
    out << "\nCommande numero: " << c.numero << endl;
    out << "Date: " << c.date << endl;
    out << "Produits:" << endl;

    // Affichage de chaque produit commandé
    // Utilisation du pointeur produit pour accéder aux informations
    for (int i = 0; i < c.produitsCommandes.size(); i++) {
        out << "- " << c.produitsCommandes[i].produit->getNom()
            << " x " << c.produitsCommandes[i].quantite << endl;
    }

    // Affichage du total (TTC)
    out << "Total: " << c.total << " DH" << endl;
    
    return out;  // Retourne le flux pour permettre cout << c1 << c2;
}

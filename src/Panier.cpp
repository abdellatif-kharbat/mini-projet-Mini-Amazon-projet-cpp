#include "Panier.h"

/**
 * Ajoute un produit au panier avec une certaine quantité
 * Si le produit existe déjà dans le panier, la quantité est augmentée
 * Sinon, une nouvelle ligne est créée
 * @param produit Pointeur vers le produit à ajouter (ne peut pas être nullptr)
 * @param quantite Quantité à ajouter (doit être > 0)
 */
void Panier::ajouterProduit(Produit* produit, int quantite) {
    // Validation des paramètres d'entrée
    if (produit == nullptr || quantite <= 0) {
        cout << "Produit ou quantite invalide." << endl;
        return;  // Sortie immédiate si paramètres invalides
    }

    // Parcours des lignes existantes pour vérifier si le produit est déjà dans le panier
    for (int i = 0; i < lignes.size(); i++) {
        // Utilisation de l'opérateur == surchargé dans Produit pour comparer les IDs
        if (*(lignes[i].produit) == *produit) {
            // Produit déjà présent : augmentation de la quantité
            lignes[i].quantite += quantite;
            return;  // Sortie de la fonction car mise à jour terminée
        }
    }

    // Produit non trouvé dans le panier : création d'une nouvelle ligne
    LignePanier ligne;
    ligne.produit = produit;  // Stockage du pointeur (pas de copie du produit)
    ligne.quantite = quantite;
    lignes.push_back(ligne);  // Ajout de la nouvelle ligne au panier
}

/**
 * Affiche le contenu complet du panier
 * Montre chaque produit avec sa quantité et son prix total ligne par ligne
 * Affiche également le total général du panier
 */
void Panier::afficher() const {
    // Vérification si le panier est vide
    if (lignes.empty()) {
        cout << "Le panier est vide." << endl;
        return;
    }

    cout << "\n--- Panier ---" << endl;
    
    // Parcours de toutes les lignes du panier
    for (int i = 0; i < lignes.size(); i++) {
        // Affichage formaté: Nom x Quantité = Prix total (TTC)
        cout << lignes[i].produit->getNom()
             << " x " << lignes[i].quantite
             << " = " << lignes[i].produit->calculerPrixFinal() * lignes[i].quantite
             << " DH" << endl;
    }
    
    // Affichage du total général
    cout << "Total: " << calculerTotal() << " DH" << endl;
}

/**
 * Calcule le montant total du panier (tous produits confondus)
 * Utilise le prix final TTC de chaque produit (calculé selon son type)
 * @return Somme de (prix TTC * quantité) pour toutes les lignes
 */
double Panier::calculerTotal() const {
    double total = 0;
    
    // Accumulation des totaux ligne par ligne
    for (int i = 0; i < lignes.size(); i++) {
        total += lignes[i].produit->calculerPrixFinal() * lignes[i].quantite;
    }
    
    return total;
}

/**
 * Vérifie si le panier est vide
 * @return true si aucune ligne dans le panier, false sinon
 */
bool Panier::estVide() const {
    return lignes.empty();  // empty() retourne true si le vecteur a taille 0
}

/**
 * Récupère toutes les lignes du panier (copie)
 * @return Copie du vecteur contenant toutes les lignes de commande
 * @note Utilisé notamment pour la validation de commande et les vérifications de stock
 */
vector<LignePanier> Panier::getLignes() const {
    return lignes;  // Retourne une copie (pas de référence) pour éviter les modifications externes
}

/**
 * Vide complètement le panier
 * Supprime toutes les lignes après validation d'une commande
 */
void Panier::vider() {
    lignes.clear();  // clear() supprime tous les éléments du vecteur
}

/**
 * Surcharge de l'opérateur += pour ajouter facilement un produit
 * Permet d'écrire: panier += produit;
 * @param produit Pointeur vers le produit à ajouter
 * @return Référence vers le panier (pour permettre les appels chaînés)
 * 
 * Exemple d'utilisation: panier += produit1 += produit2; (ajoute les deux)
 */
Panier& Panier::operator+=(Produit* produit) {
    ajouterProduit(produit, 1);  // Ajoute 1 exemplaire du produit
    return *this;  // Retourne l'objet courant pour permettre le chaînage
}

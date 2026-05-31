#include "Client.h"

// ==================== CONSTRUCTEURS ====================

/**
 * Constructeur par défaut - Crée un client vide
 * Utilisé lors de l'initialisation ou en cas d'erreur
 */
Client::Client() {
    id = 0;                 // Identifiant nul (invalide)
    nom = "";               // Nom vide
    email = "";             // Email vide
}

/**
 * Constructeur paramétré - Crée un client avec des informations complètes
 * @param id Identifiant unique du client (généré automatiquement dans la vraie application)
 * @param nom Nom complet du client
 * @param email Adresse email du client (pour communication/confirmation)
 * 
 * Note: L'historique des commandes est initialisé vide automatiquement
 */
Client::Client(int id, string nom, string email) {
    this->id = id;
    this->nom = nom;
    this->email = email;
    // L'attribut 'historique' (vector<Commande>) est automatiquement initialisé vide
}

// ==================== GETTERS ====================

/**
 * Récupère l'identifiant unique du client
 * @return ID du client (entier positif)
 */
int Client::getId() const {
    return id;
}

/**
 * Récupère le nom du client
 * @return Nom complet du client
 */
string Client::getNom() const {
    return nom;
}

// ==================== GESTION DE L'HISTORIQUE ====================

/**
 * Ajoute une commande à l'historique du client
 * @param commande Commande validée à ajouter (copie)
 * 
 * Note: Une copie de la commande est stockée dans l'historique.
 * Cela permet de conserver l'état exact de la commande même si
 * l'objet original est modifié ou détruit.
 * 
 * Exemple d'utilisation:
 * Commande cmd(1, lignes, 3648);
 * client.ajouterCommande(cmd);  // Stocke une copie de cmd
 */
void Client::ajouterCommande(Commande commande) {
    historique.push_back(commande);  // Ajoute une copie au vecteur
}

/**
 * Affiche tout l'historique des commandes du client
 * Montre chaque commande avec:
 * - Numéro de commande
 * - Date
 * - Liste des produits avec quantités
 * - Total payé
 * 
 * Si le client n'a jamais commandé, affiche un message approprié
 */
void Client::afficherHistorique() const {
    cout << "\n--- Historique de " << nom << " ---" << endl;
    
    // Vérification si le client n'a pas d'historique
    if (historique.empty()) {
        cout << "Aucune commande." << endl;
        return;  // Sortie anticipée si vide
    }

    // Parcours et affichage de chaque commande
    // Utilisation de l'opérateur << surchargé dans Commande
    for (int i = 0; i < historique.size(); i++) {
        cout << historique[i] << endl;  // Affiche une commande à la fois
    }
}

// ==================== SURCHARGE DES OPERATEURS ====================

/**
 * Surcharge de l'opérateur << pour l'affichage des informations client
 * Permet d'écrire directement: cout << client;
 * 
 * @param out Flux de sortie (généralement cout)
 * @param c Client à afficher (constante - ne modifie pas l'objet)
 * @return Référence vers le flux de sortie (pour permettre le chaînage)
 * 
 * Format d'affichage: Client: Yassine | Email: yassine@gmail.com
 */
ostream& operator<<(ostream& out, const Client& c) {
    out << "Client: " << c.nom << " | Email: " << c.email;
    return out;  // Retourne le flux pour permettre cout << c1 << c2;
}

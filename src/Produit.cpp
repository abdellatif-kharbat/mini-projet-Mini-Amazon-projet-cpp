#include "Produit.h"

// ==================== CLASSE PRODUIT (CLASSE DE BASE) ====================

/**
 * Constructeur par défaut - Initialise un produit vide
 */
Produit::Produit() {
    id = 0;
    nom = "";
    prix = 0;
    stock = 0;
}

/**
 * Constructeur paramétré - Initialise un produit avec des valeurs spécifiques
 * @param id Identifiant unique du produit
 * @param nom Nom du produit
 * @param prix Prix unitaire hors taxes
 * @param stock Quantité disponible en stock
 */
Produit::Produit(int id, string nom, double prix, int stock) {
    this->id = id;
    this->nom = nom;
    this->prix = prix;
    this->stock = stock;
}

/**
 * Destructeur virtuel - Permet une destruction polymorphique correcte
 * Les classes dérivées seront correctement détruites
 */
Produit::~Produit() {
    // Rien à libérer dans cette classe de base
}

// ==================== GETTERS ====================

/**
 * @return L'identifiant du produit
 */
int Produit::getId() const {
    return id;
}

/**
 * @return Le nom du produit
 */
string Produit::getNom() const {
    return nom;
}

/**
 * @return Le prix unitaire hors taxes
 */
double Produit::getPrix() const {
    return prix;
}

/**
 * @return La quantité en stock
 */
int Produit::getStock() const {
    return stock;
}

// ==================== SETTERS ET METHODES DE GESTION ====================

/**
 * Modifie la quantité en stock
 * @param stock Nouvelle quantité en stock
 */
void Produit::setStock(int stock) {
    this->stock = stock;
}

/**
 * Diminue le stock d'une certaine quantité après une commande
 * @param quantite Quantité à retirer du stock
 * @note Vérifie que la quantité ne dépasse pas le stock disponible
 */
void Produit::diminuerStock(int quantite) {
    if (quantite <= stock) {
        stock -= quantite;  // Réduction du stock seulement si assez disponible
    }
    // Si quantite > stock, rien ne se passe (stock inchangé)
}

// ==================== METHODES VIRTUELLES ====================

/**
 * Retourne le type du produit (surchargé par les classes dérivées)
 * @return String indiquant le type de produit
 */
string Produit::getType() const {
    return "Produit";
}

/**
 * Calcule le prix final TTC (avec TVA par défaut 20%)
 * Cette méthode est virtuelle et sera redéfinie dans les classes dérivées
 * @return Prix final après application de la TVA
 */
double Produit::calculerPrixFinal() const {
    return prix * 1.20; // TVA standard à 20%
}

// ==================== SURCHARGE DES OPERATEURS ====================

/**
 * Compare deux produits par leur ID
 * @param p Produit à comparer
 * @return true si les IDs sont identiques
 */
bool Produit::operator==(const Produit& p) const {
    return id == p.id;
}

/**
 * Compare deux produits par leur prix (pour le tri)
 * @param p Produit à comparer
 * @return true si ce produit est moins cher que p
 */
bool Produit::operator<(const Produit& p) const {
    return prix < p.prix;
}

/**
 * Surcharge de l'opérateur << pour l'affichage
 * Permet d'afficher facilement un produit avec cout << produit
 * @param out Flux de sortie
 * @param p Produit à afficher
 * @return Référence vers le flux de sortie
 */
ostream& operator<<(ostream& out, const Produit& p) {
    out << "ID: " << p.id << " | Nom: " << p.nom
        << " | Type: " << p.getType()          // Polymorphisme: appel à la méthode de la classe dérivée
        << " | Prix: " << p.prix
        << " | Prix avec TVA/remise: " << p.calculerPrixFinal()  // Polymorphisme: calcul spécifique
        << " | Stock: " << p.stock;
    return out;
}

// ==================== CLASSE PRODUIT ELECTRONIQUE ====================

/**
 * Constructeur pour un produit électronique
 * @param id Identifiant
 * @param nom Nom du produit
 * @param prix Prix HT
 * @param stock Quantité en stock
 * @param garantie Durée de garantie en mois
 */
ProduitElectronique::ProduitElectronique(int id, string nom, double prix, int stock, int garantie)
    : Produit(id, nom, prix, stock) {  // Appel du constructeur de la classe de base
    this->garantie = garantie;
}

/**
 * Redéfinition du type pour les produits électroniques
 */
string ProduitElectronique::getType() const {
    return "Electronique";
}

/**
 * Calcul du prix final pour un produit électronique
 * Application d'une remise de 5% puis TVA à 20%
 * @return Prix final = (prix HT - 5%) + TVA 20%
 */
double ProduitElectronique::calculerPrixFinal() const {
    double prixRemise = prix - (prix * 0.05); // Remise de 5% sur le prix HT
    return prixRemise * 1.20;                 // Application de la TVA 20%
}

// ==================== CLASSE PRODUIT ALIMENTAIRE ====================

/**
 * Constructeur pour un produit alimentaire
 * @param id Identifiant
 * @param nom Nom du produit
 * @param prix Prix HT
 * @param stock Quantité en stock
 * @param dateExpiration Date limite de consommation (format MM/YYYY)
 */
ProduitAlimentaire::ProduitAlimentaire(int id, string nom, double prix, int stock, string dateExpiration)
    : Produit(id, nom, prix, stock) {
    this->dateExpiration = dateExpiration;
}

/**
 * Redéfinition du type pour les produits alimentaires
 */
string ProduitAlimentaire::getType() const {
    return "Alimentaire";
}

/**
 * Calcul du prix final pour un produit alimentaire
 * TVA réduite à 7% (pas de remise)
 * @return Prix final = prix HT + TVA 7%
 */
double ProduitAlimentaire::calculerPrixFinal() const {
    return prix * 1.07; // TVA réduite à 7% (produits de première nécessité)
}

// ==================== CLASSE VETEMENT ====================

/**
 * Constructeur pour un vêtement
 * @param id Identifiant
 * @param nom Nom du produit (ex: "T-shirt", "Jean")
 * @param prix Prix HT
 * @param stock Quantité en stock
 * @param taille Taille du vêtement (S, M, L, XL, etc.)
 */
Vetement::Vetement(int id, string nom, double prix, int stock, string taille)
    : Produit(id, nom, prix, stock) {
    this->taille = taille;
}

/**
 * Redéfinition du type pour les vêtements
 */
string Vetement::getType() const {
    return "Vetement";
}

/**
 * Calcul du prix final pour un vêtement
 * Application d'une remise de 10% puis TVA à 20%
 * @return Prix final = (prix HT - 10%) + TVA 20%
 */
double Vetement::calculerPrixFinal() const {
    double prixRemise = prix - (prix * 0.10); // Remise de 10% (soldes, promotions)
    return prixRemise * 1.20;                 // Application de la TVA 20%
}

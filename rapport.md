# Rapport du mini-projet Mini Amazon

## 1. Introduction

Ce mini-projet est une application console en C++ qui simule une petite
plateforme e-commerce. Le client peut consulter le catalogue, ajouter des
produits au panier, valider une commande et voir son historique.

Le projet a ete realise pour pratiquer les notions de la Programmation Orientee
Objet vues en cours.

## 2. Diagramme de cas d'utilisation

```mermaid
flowchart LR
    Client((Client))
    A[Afficher catalogue]
    B[Ajouter au panier]
    C[Afficher panier]
    D[Valider commande]
    E[Voir historique]

    Client --> A
    Client --> B
    Client --> C
    Client --> D
    Client --> E
```

### Explication

Le client utilise le programme a travers un menu. Il peut voir les produits,
ajouter un produit au panier, afficher le panier, valider la commande et
consulter son historique.

## 3. Diagramme de classes

```mermaid
classDiagram
    class Produit {
        #int id
        #string nom
        #double prix
        #int stock
        +getType()
        +calculerPrixFinal()
    }

    class ProduitElectronique {
        -int garantie
        +getType()
        +calculerPrixFinal()
    }

    class ProduitAlimentaire {
        -string dateExpiration
        +getType()
        +calculerPrixFinal()
    }

    class Vetement {
        -string taille
        +getType()
        +calculerPrixFinal()
    }

    class Panier {
        -vector lignes
        +ajouterProduit()
        +calculerTotal()
        +vider()
    }

    class Commande {
        -int numero
        -double total
        +afficher()
    }

    class Client {
        -int id
        -string nom
        -string email
        -vector historique
        +ajouterCommande()
        +afficherHistorique()
    }

    Produit <|-- ProduitElectronique
    Produit <|-- ProduitAlimentaire
    Produit <|-- Vetement
    Panier --> Produit
    Commande --> Produit
    Client --> Commande
```

### Explication

La classe `Produit` est la classe principale. Les classes
`ProduitElectronique`, `ProduitAlimentaire` et `Vetement` heritent de cette
classe. Chaque type de produit a sa propre methode pour calculer le prix final.

La classe `Panier` garde les produits choisis par le client. Quand la commande
est validee, un objet `Commande` est cree et ajoute dans l'historique du
`Client`.

## 4. Diagramme de sequence

```mermaid
sequenceDiagram
    participant Client
    participant Panier
    participant Produit
    participant Commande

    Client->>Panier: ajouter produit
    Client->>Panier: valider commande
    Panier->>Produit: verifier stock
    Panier->>Produit: diminuer stock
    Panier->>Commande: creer commande
```

### Explication

Avant de valider une commande, le programme verifie si le panier n'est pas vide
et si le stock est suffisant. Apres la validation, le stock est diminue et le
panier est vide.

## 5. Concepts POO utilises

- Encapsulation avec les attributs prives et proteges.
- Heritage entre `Produit` et les classes filles.
- Polymorphisme avec `getType()` et `calculerPrixFinal()`.
- Surcharge des operateurs comme `<<`, `==`, `<` et `+=`.
- Fonction amie pour afficher certains objets avec `cout`.

## 6. Conclusion

Ce projet reste simple, mais il montre les bases de la POO en C++. Il nous a
permis de mieux comprendre l'organisation d'un programme avec plusieurs classes
et fichiers.

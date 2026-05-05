#ifndef PRODUIT_H
#define PRODUIT_H

#include <iostream>
#include <string>

using namespace std;

class Produit {
protected:
    int id;
    string nom;
    double prix;
    int stock;

public:
    Produit();
    Produit(int id, string nom, double prix, int stock);
    virtual ~Produit();

    int getId() const;
    string getNom() const;
    double getPrix() const;
    int getStock() const;

    void setStock(int stock);
    void diminuerStock(int quantite);

    virtual string getType() const;
    virtual double calculerPrixFinal() const;

    bool operator==(const Produit& p) const;
    bool operator<(const Produit& p) const;

    friend ostream& operator<<(ostream& out, const Produit& p);
};

class ProduitElectronique : public Produit {
private:
    int garantie;

public:
    ProduitElectronique(int id, string nom, double prix, int stock, int garantie);
    string getType() const override;
    double calculerPrixFinal() const override;
};

class ProduitAlimentaire : public Produit {
private:
    string dateExpiration;

public:
    ProduitAlimentaire(int id, string nom, double prix, int stock, string dateExpiration);
    string getType() const override;
    double calculerPrixFinal() const override;
};

class Vetement : public Produit {
private:
    string taille;

public:
    Vetement(int id, string nom, double prix, int stock, string taille);
    string getType() const override;
    double calculerPrixFinal() const override;
};

#endif

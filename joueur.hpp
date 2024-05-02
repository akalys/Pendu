

#ifndef JOUEUR_CLASS
#define JOUEUR_CLASS

#include <iostream>
#include <string>


using namespace std;

class Joueur
{
public:
    Joueur(const string &n);
    virtual ~Joueur();
    const string &getNom() const;
    unsigned int getPoints() const;
    unsigned int getEtape() const;
    void incrPoints();
    void incrEtape();
    void reset();

    // Le joueur propose un mot
    virtual string proposerMot() = 0;
    // Le joueur propose une lettre
    virtual char proposerLettre() = 0;

private:
    string j_nom;           // Nom du joueur
    unsigned int j_npoints; // Points cumulés
    unsigned int j_etape;   // Etape
};

#endif

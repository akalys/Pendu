#ifndef JEU_PENDU_HPP
#define JEU_PENDU_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

#include "joueur.hpp"


class jeuPendu
{
public:
    jeuPendu(vector<Joueur *> &j);
    void afficher();
    void jouer();

protected:
    bool estDansMot(char c);
    void inclureDansMot(char c);
    void initADeviner(unsigned k);
    void initTentative();
    bool devinerMot(unsigned k); 

private:
    vector<Joueur *> &m_joueurs;
    string m_adeviner;  // mot caché
    string m_tentative; // mot tenté
};

#endif 
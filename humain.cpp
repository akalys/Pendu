#include "Humain.hpp"

/**
 * @brief Constructeur
 *
 * @param n Le nom du joueur humain
 */
Humain::Humain(const string &n) : Joueur(n) {}

/**
 * @brief Celui qui fait deviner propose son mot
 *
 * @return Le mot à deviner par les autres joueurs
 */
string Humain::proposerMot() 
{
    cout << "(Les autres joueurs, ne regardez pas !)" << endl;
    cout << "Mot proposé ? ";
    string s;
    cin >> s;
    return s;
}

/**
 * @brief Les joueurs propose une lettre
 * 
 * @return Lettre potentiellement présente dans le mot
 */
char Humain::proposerLettre()
{
    char c;
    cin >> c;
    return c;
}
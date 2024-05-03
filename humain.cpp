#include "Humain.hpp"
#include <iostream>
#include <cctype>
#include <conio.h>  // Nécessaire pour _getch()

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
    cout << "(Si ce n'est pas a toi d'ecrire un mot, il ne faut pas que tu regardes par ici)" << endl;
    cout << "Mot propose ? ";
    string s;
    cin >> s;
    return s;
}

/**
 * @brief Les joueurs propose un caractère. Si le caractère est une lettre, 
 * alors ce sera la lettre proposée par le joueur
 * @return Lettre potentiellement présente dans le mot
 */
char Humain::proposerLettre()
{
    char c;
    do {
        c = _getch();
        c = tolower(c);
    } while (!isalpha(c)); 
    return c;
}
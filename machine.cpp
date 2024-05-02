#include "machine.hpp"
#include <cstdlib>
#include <ctime>

/**
 * @brief Constructeur de Machine
 */
Machine::Machine(const string &n, const vector<string> &d)
    : Joueur(n), m_dict(d)
{
    srand(time(nullptr)); // Initialise le générateur de nombres aléatoires
}

/**
 * @brief L'IA choisit un mot aléatoire pour la partie
 *
 * @return Le mot à deviner
 */
string Machine::proposerMot() 
{
    int index = rand() % m_dict.size(); // Sélection aléatoire d'un index
    cout << "Mot proposé: " << m_dict[index] << endl;
    return m_dict[index];
}

/**
 * @brief L'IA propose une lettre pour remplir le mot
 *
 * @return char
 */
char Machine::proposerLettre() {
    char c = 'a' + rand() % 26; // Génère une lettre aléatoire de l'alphabet
    std::cout << "Lettre proposée: " << c << endl;
    return c;
}

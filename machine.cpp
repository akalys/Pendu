#include "machine.hpp"
#include "jeuPendu.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <chrono>
#include <thread>

void delay(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

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
    return m_dict[index];
}

/**
 * @brief L'IA propose une lettre pour remplir le mot
 *
 * @return char
 */
char Machine::proposerLettre() {
    char tirage; 
    do {
        tirage = 'a' + rand() % 26; // Génère une lettre aléatoire de l'alphabet
    } while (lettresDejaUtilisees.find(tirage) != lettresDejaUtilisees.end());

    lettresDejaUtilisees.insert(tirage); // Ajoute la lettre tirée à l'ensemble des lettres déjà utilisées

    std::cout << " " << tirage << std::endl;
    delay(2);
    return tirage;
    
}

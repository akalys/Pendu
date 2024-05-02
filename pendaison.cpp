#include "Pendaison.hpp"

/**
 * @brief Pour chaque étape, affichage de la potence
 * sur le terminal selon l'avancée du mot
 * @param j_etape Etape de recherche du mot
 */
void Pendaison::afficher(unsigned int j_etape)
{
    switch (j_etape)
    {
    case 0:
        std::cout << " ______" << std::endl;
        std::cout << "|/    |" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|______" << std::endl;
        break;
    case 1:
        std::cout << " ______" << std::endl;
        std::cout << "|/    |" << std::endl;
        std::cout << "|     O" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|______" << std::endl;
        break;
    case 2:
        std::cout << " ______" << std::endl;
        std::cout << "|/    |" << std::endl;
        std::cout << "|     O" << std::endl;
        std::cout << "|     |" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|______" << std::endl;
        break;
    case 3:
        std::cout << " ______" << std::endl;
        std::cout << "|/    |" << std::endl;
        std::cout << "|     O" << std::endl;
        std::cout << "|    /|" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|______" << std::endl;
        break;
    case 4:
        std::cout << " ______" << std::endl;
        std::cout << "|/    |" << std::endl;
        std::cout << "|     O" << std::endl;
        std::cout << "|    /|\\" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|______" << std::endl;
        break;
    case 5:
        std::cout << " ______" << std::endl;
        std::cout << "|/    |" << std::endl;
        std::cout << "|     O" << std::endl;
        std::cout << "|    /|\\" << std::endl;
        std::cout << "|    /" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|______" << std::endl;
        break;
    case 6:
        std::cout << " ______" << std::endl;
        std::cout << "|/    |" << std::endl;
        std::cout << "|     O" << std::endl;
        std::cout << "|    /|\\" << std::endl;
        std::cout << "|    / \\" << std::endl;
        std::cout << "|" << std::endl;
        std::cout << "|______" << std::endl;
        break;
    default:
        break;
    }
}

/**
 * @brief Vérifie si le joueur est pendu
 *
 * @param j_etape Le numéro de l'étape
 * @return true si le joueur est pendu sinon false
 */
bool Pendaison::estPendu(unsigned j_etape)
{
    return j_etape >= 6;
}
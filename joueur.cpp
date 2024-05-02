
#include "joueur.hpp"
#include "jeuPendu.hpp"


/**
 * @brief Constructeur de joueur
 *
 * @param n le nom du joueur
 */
Joueur::Joueur(const string &n) : j_nom(n), j_npoints(0), j_etape(0) {}

/**
 * @brief Destructeur virtuel de joueur
 */
Joueur::~Joueur() {}

/**
 * @brief Acces au nom du joueur
 *
 * @return Le nom du joueur
 */
const string &Joueur::getNom() const
{
    return j_nom;
}

/**
 * @brief Acces au nombre de points du joueur
 *
 * @return Le nombre de points du joueur
 */
unsigned int Joueur::getPoints() const
{
    return j_npoints;
}

/**
 * @brief Acces à l'étape atteinte par le joueur
 *
 * @return L'étape atteinte
 */
unsigned int Joueur::getEtape() const
{
    return j_etape;
}

/**
 * @brief Modification du nombre de points du joueur
 *
 */
void Joueur::incrPoints()
{
    ++j_npoints;
}

/**
 * @brief Modification du numero etape
 *
 */
void Joueur::incrEtape()
{
    ++j_etape;
}

/**
 * @brief Reinitialisation du nombre d'étapes
 * avant de recommencer une partie
 */
void Joueur::reset()
{
    j_etape = 0;
}

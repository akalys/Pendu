
#include "jeuPendu.hpp"
#include "pendaison.hpp"
#include "algorithm"
#include <chrono>
#include <thread>

/**
 * @brief Constructeur de jeu pendu 
 * 
 * @param j Les joueurs
 */
jeuPendu::jeuPendu(vector<Joueur *> &j) : m_joueurs(j) {}

/**
 * @brief Affiche les résultats à la fin de la partie
 */
void jeuPendu::afficher()
{
    std::cout << endl
         << "Partie Finie ! Resultats : " << endl;
    for (unsigned int j = 0; j < m_joueurs.size(); j++) // Chaque joueur est analysé une fois
    {
        Joueur &joueur = *m_joueurs[j];
        std::cout << "Joueur "
             << joueur.getNom() // On ressort le nom 
             << " (" << (j + 1) << ") => " // Si c'est le joueur 1 ou le joueur 2
             << (!Pendaison::estPendu(joueur.getEtape()) ? "EN VIE" : "PENDU") // Son état à la fin de la partie
             << " Points : " << joueur.getPoints() << endl; // Son nombre de points
    }
    std::cout << endl;
}

/**
 * @brief Fonction booléenne qui indique si le mot
 * a été deviné ou non 
 * @param k Le numéro du joueur qui a proposé le mot
 * @return true si le joueur trouve le mot sinon false 
 */
bool jeuPendu::devinerMot(unsigned k)
{
    /*On continue de jouer tant que un joueur a reussi à jouer et
    que le mot n'est pas deviné */
    for (;;)
    {
        bool ajouer = false;
        for (unsigned j = 0; j < m_joueurs.size(); j++)
        {
            // On passe le joueur k qui a proposé le mot
            if (j == k)
            {
                continue;
            }

            Joueur &joueur = *m_joueurs[j];

            // On vérifie si le joueur j peut encore jouer
            if (Pendaison::estPendu(joueur.getEtape()))
            {
                continue;
            }

            // Un joueur a réussi à jouer
            ajouer = true;

            /* Affiche la tentative actuelle, le statut du joueur j
            et lui demande sa lettre */
            std::cout << "Lettres deja utilisees : ";
            for (char lettre : lettresUtilisees)
            {
                std::cout << lettre << ' ';
            }
            std::cout << endl;
            unsigned int nEssaisRestant = 7 - joueur.getEtape();
            std::cout << endl
                 << "Il te reste " << nEssaisRestant << " essai(s). " << endl;

            std::cout << endl
                 << "Tentative : " << m_tentative << endl;
            std::cout << endl
                 << "   Joueur " << joueur.getNom() << " (" << (j + 1) << ") lettre ? ";
            char lettre = joueur.proposerLettre();
            system("cls");

            // Teste si la lettre est dans le mot et actualise le score

            if (estDansMot(lettre))
            {
                Pendaison::afficher(joueur.getEtape());
                inclureDansMot(lettre);
                std::cout << "Bravo: " << m_tentative << endl;
                if (m_tentative == m_adeviner)
                {
                    joueur.incrPoints();
                    std::cout << "==> GAGNE !" << endl;
                    return true;
                }
            }
            else
            {
                unsigned int nEssaisRestant = 6 - joueur.getEtape();
                Pendaison::afficher(joueur.getEtape());

                std::cout << "Rate !" << endl;

                if (find(lettresUtilisees.begin(), lettresUtilisees.end(), lettre) == lettresUtilisees.end()) // Recherche si la lettre a déjà été utilisée
                {
                    joueur.incrEtape(); 
                    lettresUtilisees.push_back(lettre); // Ajoute la lettre utilisée
                }
                else
                {
                    std::cout << "Vous avez deja essaye cette lettre !\n";
                }

                if (Pendaison::estPendu(joueur.getEtape()))
                {
                    std::cout << "==> PERDU" << endl;
                    m_joueurs[k]->incrPoints();
                    
                   
                    return false;
                }
            }
        }
        if (not ajouer)
        {
            return false;
        }
    }
}

/**
 * @brief Lancement d'une partie
 */
void jeuPendu::jouer()
{
    // Reinitialise les statuts des joueurs
    for (unsigned int k = 0; k < m_joueurs.size(); ++k)
    {
        m_joueurs[k]->reset();
    }

    // Fait jouer les joueurs chacun leur tour
    for (unsigned int k = 0; k < m_joueurs.size(); k++)
    {
        // Initialise le mot à deviner le joueur k
        initADeviner(k);

        // Initialise la tentative
        initTentative();

        // Les autres joueurs doivent proposer des lettres
        bool b = devinerMot(k);
        if (not b)
        {
            std::cout << "Le mot a deviner etait: " << m_adeviner << endl;
            std::this_thread::sleep_for(std::chrono::seconds(3)); // Delai pour un affichage plus propre
            system("cls"); // Efface le terminal
        }
    }
}

bool jeuPendu::estDansMot(char c)
{
    return (m_adeviner.find(c) != string::npos) and (m_tentative.find(c) == string::npos);
}

void jeuPendu::inclureDansMot(char c)
{
    for (unsigned int j = 0; j < m_tentative.size(); j++)
    {

        if (tolower(c) == m_adeviner[j])
        {
            m_tentative[j] = c;
        }
    }
}

void jeuPendu::initADeviner(unsigned int k)
{
    std::cout << endl
         << "Au joueur "
         << m_joueurs[k]->getNom()
         << " (" << (k + 1) << ") de proposer un mot" << endl
         << endl;
    m_adeviner = m_joueurs[k]->proposerMot();
}

void jeuPendu::initTentative()
{
    m_tentative = string(m_adeviner.size(), '_');
    lettresUtilisees.clear();
}


#include "jeuPendu.hpp"
#include "pendaison.hpp"
#include "algorithm"
#include <chrono>
#include <thread>

jeuPendu::jeuPendu(vector<Joueur *> &j) : m_joueurs(j) {}

void jeuPendu::afficher()
{
    cout << endl
         << "Partie Finie ! Resultats : " << endl;
    for (unsigned int j = 0; j < m_joueurs.size(); j++)
    {
        Joueur &joueur = *m_joueurs[j];
        cout << "Joueur "
             << joueur.getNom()
             << " (" << (j + 1) << ") => "
             << (!Pendaison::estPendu(joueur.getEtape()) ? "EN VIE" : "PENDU")
             << " Points : " << joueur.getPoints() << endl;
    }
    cout << endl;
}

bool jeuPendu::devinerMot(unsigned k)
{
    /*On continue de jouer tant que un joueur a reussi à jouer
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
            cout << endl;
            unsigned int nEssaisRestant = 7 - joueur.getEtape();
            cout << endl
                 << "Il te reste " << nEssaisRestant << " essai(s). " << endl;

            cout << endl
                 << "Tentative : " << m_tentative << endl;
            cout << endl
                 << "   Joueur " << joueur.getNom() << " (" << (j + 1) << ") lettre ? ";
            char lettre = joueur.proposerLettre();
            system("cls");
            // Teste si la lettre est dans le mot et actualise le score

            if (estDansMot(lettre))
            {
                Pendaison::afficher(joueur.getEtape());
                inclureDansMot(lettre);
                cout << "Bravo: " << m_tentative << endl;
                if (m_tentative == m_adeviner)
                {
                    joueur.incrPoints();
                    cout << "==> GAGNE !" << endl;
                    return true;
                }
            }
            else
            {
                unsigned int nEssaisRestant = 6 - joueur.getEtape();
                Pendaison::afficher(joueur.getEtape());

                cout << "Rate !" << endl;
                if (find(lettresUtilisees.begin(), lettresUtilisees.end(), lettre) == lettresUtilisees.end())
                {
                    joueur.incrEtape();
                    lettresUtilisees.push_back(lettre); // Ajouter la lettre utilisée
                }
                else
                {
                    std::cout << "Vous avez deja essaye cette lettre !\n";
                }

                if (Pendaison::estPendu(joueur.getEtape()))
                {
                    cout << "==> PERDU" << endl;
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
            cout << "Le mot a deviner etait: " << m_adeviner << endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
            system("cls");
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
    cout << endl
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

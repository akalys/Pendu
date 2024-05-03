#include "humain.hpp"
#include "jeuPendu.hpp"
#include "machine.hpp"
#include <vector>
#include <iostream>
#include <cctype>
#include <fstream>
#include <iterator>

/**
 * @brief Déroulement d'une partie à
 * deux joueurs
 */
void jeucontreHumain() {
    cout << "Joueur 1 : Votre Nom ?" << endl; 
    string nom1; 
    cin >> nom1; 
    Humain j1(nom1);

    cout << "Joueur 2 : Votre Nom ?" << endl; 
    string nom2; 
    cin >> nom2; 
    Humain j2(nom2);

    vector<Joueur*> joueurs {&j1, &j2};
    jeuPendu jeu(joueurs);

    char c;
    do {
        jeu.jouer();
        jeu.afficher();
        cout << "Voulez-vous jouer encore ? (o/n) : ";
        cin >> c;
    } while (tolower(c) == 'o');
}

/**
 * @brief Partie contre l'IA
 */
void jeucontreMachine() {
    ifstream is("dictionnaire.txt");
    if (!is) {
        cerr << "Erreur à l'ouverture du fichier dictionnaire." << endl;
        return;
    }

    vector<string> dico((istream_iterator<string>(is)), istream_iterator<string>());
    is.close();

    cout << "Votre Nom ?" << endl;
    string nom;
    cin >> nom;
    Humain j1(nom);
    Machine j2("Ordinateur", dico);

    vector<Joueur*> joueurs {&j1, &j2};
    jeuPendu jeu(joueurs);

    char c;
    do {
        jeu.jouer();
        jeu.afficher();
        cout << "Voulez-vous jouer encore ? (o/n) : ";
        cin >> c;
    } while (tolower(c) == 'o');
}

/**
 * @brief Affichage principale qui fait office de menu 
 */
int main() {
    char choix;
    do {
        system("cls");
        cout << "Bienvenue dans le jeu du Pendu!\n";
        cout << "Voulez-vous jouer une partie ? (o/n) : ";
        cin >> choix;
        choix = tolower(choix);

        if (choix == 'o') {
            system("cls"); 
            cout << "1. Jouer contre l'ordinateur\n";
            cout << "2. Jouer contre un autre humain\n";
            cout << "3. Quitter\n";
            cout << "Entrez votre choix (1, 2 ou 3) : ";
            cin >> choix;

            switch (choix) {
                case '1':
                system("cls");
                    jeucontreMachine();
                    break;
                case '2':
                system("cls");
                    jeucontreHumain();
                    break;
                case '3':
                system("cls");
                    cout << "Merci d'avoir joué. À bientôt!\n";
                    exit(0);
                default:
                    cout << "Choix invalide.\n";
            }
        } else if (choix == 'n') {
            cout << "Merci d'avoir joué. À bientôt!\n";
            break;
        } else {
            cout << "Choix invalide.\n";
        }
    } while (true);

    return 0;
}

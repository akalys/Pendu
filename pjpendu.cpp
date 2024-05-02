#include "humain.hpp"
#include "jeuPendu.hpp"
#include "machine.hpp"
#include <vector>
#include <iostream>
#include <cctype>
#include <fstream>
#include <iterator>

/**
 * @brief Lance la partie entre deux joueurs humains
 */
void jeucontreHumain()
{
    // Instancie les joueurs
    cout << "Joueur 1 : Votre Nom ?" << endl; 
    string Humain1; 
    cin >> Humain1; 

    Humain j1(Humain1);

    cout << "Joueur 2 : Votre Nom ?" << endl; 
    string Humain2; 
    cin >> Humain2; 
    Humain j2(Humain2);

    vector<Joueur *> joueurs;
    joueurs.push_back(&j1);
    joueurs.push_back(&j2);

    // Instancie un jeu de Pendu
    jeuPendu jeu(joueurs);

    // Effectue les parties
    cout << "Une partie ? (o/n)";
    char c;
    cin >> c;
    while (tolower(c) == 'o')
    {
        jeu.jouer();
        jeu.afficher();
        cout << "Une autre partie ? (o/n) ";
        cin>>c; 
    }
}

/**
 * @brief Lance une partie entre l'IA et la machine
 */
void jeucontreMachine(){

    //On vérifie si le fichier s'ouvre sans problème
    ifstream is("dictionnaire.txt");
    if (!is) {
        cerr << "Erreur à l'ouverture du fichier dictionnaire." << endl;
        return;
    }

    // Charge le dictionnaire
    vector<string> dico((istream_iterator<string>(is)), istream_iterator<string>());
    is.close();

    //Instancie les joueurs
    cout << "Joueur 1 : Votre Nom ?" << endl; 
    string Humain1; 
    cin >> Humain1; 

    Humain j1(Humain1);
    Machine j2("Ordinateur", dico);

    vector<Joueur *> joueurs;
    joueurs.push_back(&j1);
    joueurs.push_back(&j2);

    jeuPendu jeu(joueurs);
    
    cout << "Une partie ? (o/n)";
    char c;
    cin >> c;
    while (tolower(c) == 'o')
    {
        jeu.jouer();
        jeu.afficher();
        cout << "Une autre partie ? (o/n) ";
        cin>>c; 
    }
}

int main() {
    char choix;
    cout << "Voulez-vous jouer contre l'IA (i) ou contre un humain (h) ? ";
    cin >> choix;
    choix = tolower(choix);
    if (choix == 'i') {
        jeucontreMachine();
    } else if (choix == 'h') {
        jeucontreHumain();
    } else {
        cout << "Choix invalide. Veuillez choisir 'i' pour jouer contre l'IA ou 'h' pour jouer contre un humain." << endl;
    }
    return 0;
}
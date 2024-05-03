# Jeu du Pendu

Le jeu du pendu est un jeu classique où le joueur doit deviner un mot en proposant des lettres. Ce projet de jeu du pendu est une implémentation en C++ avec des joueurs humains et une intelligence artificielle basique pour jouer contre l'ordinateur.

## Structure du Projet

Le projet est structuré autour de plusieurs classes définies pour gérer les joueurs (humains et IA), la logique du jeu, et l'affichage de la pendaison.

### Diagramme des Dépendances
![image](https://github.com/akalys/Pendu/assets/94455527/37e56563-ef53-45f0-a87c-7f2e05303343)


### Fichiers et Classes

- **Joueur (joueur.hpp/cpp)**: Classe abstraite pour les joueurs.
- **Humain (humain.hpp/cpp)**: Classe pour les joueurs humains, dérivée de Joueur.
- **Machine (machine.hpp/cpp)**: Classe pour l'IA, dérivée de Joueur.
- **JeuPendu (jeuPendu.hpp/cpp)**: Gère la logique du jeu, utilise les objets Joueur.
- **Pendaison (pendaison.hpp/cpp)**: Fonctions statiques pour l'affichage des étapes de pendaison.
- **Main (pjpendu.cpp)**: Point d'entrée du programme.

## Étapes de Réalisation

1. **Planification du Projet**: Conception des classes et des interactions nécessaires pour le jeu.
2. **Mise en Place des Classes de Base**: Implémentation des classes Joueur, Humain, et Machine.
3. **Développement de la Logique du Jeu**: Création de la classe JeuPendu pour gérer les tours et la logique du jeu.
4. **Interface Utilisateur**: Développement des interactions dans le terminal pour jouer au jeu.
5. **Tests et Débogage**: Validation du fonctionnement du jeu et correction des bugs.
6. **Améliorations et Refactoring**: Optimisation du code et ajout de nouvelles fonctionnalités.





#pragma once

#include <stdio.h>
#include <vector>

#include "croupier.hpp"
#include "joueur.hpp"

/*
Cette classe permet de gérer le flu pour une partie. 
Constructeur : Liste de joueur -> modulable à chaque partie (possible de rajouter/retirer un joueur à chaque nouvelle partie)
printGame : Fonction auxiliaire (permet d'afficher le jeu d'une personne en particulier)
calculValue : Fonction auxiliaire (calcul la valeur du jeu par rapport au jeu de la personne)
InitialPhase : Distribue 2 cartes à chacun et affiche le jeu de tout le monde
GamePhase : Interroge chaque joueur pour savoir s'il veut piocher
EndGame : Vérifie qui à gagner
*/

class Game {
    public:
        Game(std::vector<Joueur>& ps, Croupier c);
        void printGame(std::vector<int> set);
        int calculValue(std::vector<int> set);
        void InitialPhase(void);
        void GamePhase(void);
        void EndPhase(void);
    private:
        std::vector<Joueur>& players;
        Croupier croupier;
};
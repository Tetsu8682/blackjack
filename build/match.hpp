#pragma once

#include <stdio.h>
#include <vector>
#include <string>

#include "game.hpp"
#include "joueur.hpp"
#include "croupier.hpp"
#include "paquet.hpp"

/*
La classe Match permet d'enchainer plusieurs game d'affilé, comme dans un vrai casino.
Constructeur
InitMatch : Démarrage de la table. Interroge sur le nombre de joueur
PlayGame : Permet de lancer la logique d'une game, géré par la classe Game
InterMatch : Permet de gérer les joueurs qui souhaite s'ajouter ou se retirer de la table
*/
class Match {
    public:
        Match(Croupier c, Paquet p);
        void InitMatch(void);
        void PlayGame(void);
        int InterMatch(void);
    private:
        std::vector<Joueur> players;
        Croupier croupier;
        Paquet paquet;
};
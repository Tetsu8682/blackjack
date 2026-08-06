#pragma once
#include <stdio.h>
#include <vector>
#include "croupier.hpp"
#include "joueur.hpp"


class Game {
    public:
        Game(std::vector<Joueur>& ps, Croupier c);
        void printGame(std::vector<int> set);
        int calculValue(std::vector<int> set);
        void InitialPhase(void);
        void GamePhase(void);
        void EndPhase(void);
    private:
        std::vector<Joueur> players;
        Croupier croupier;
};
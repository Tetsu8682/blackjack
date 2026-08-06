#pragma once

#include <stdio.h>
#include <vector>

#include "game.hpp"
#include "joueur.hpp"
#include "croupier.hpp"

class Match {
    public:
        Match();
        void InitMatch(void);
        void PlayGame(void);
        void InterMatch(void);
    private:
        std::vector<Joueur> players;
        Croupier croupier;
};
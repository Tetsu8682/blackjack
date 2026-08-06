#pragma once

#include <stdio.h>
#include <vector>

#include "paquet.hpp"

class Joueur {
    public:
        Joueur(Paquet *p);
        void draw(void);
        void afficher(void);
        std::vector<int> getSet(void);
        void eraseGame(void);
    private:
        std::vector<int> set;
        Paquet* currentP;
};
#pragma once

#include <stdio.h>
#include <vector>

#include "paquet.hpp"


class Croupier {
    public:
        Croupier(Paquet* p);
        void draw(void);
        void afficher(void);
        void eraseGame(void);
        std::vector<int> getSet(void);
    private:
        std::vector<int> set;
        Paquet* currentP;
};
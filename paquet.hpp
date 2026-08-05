#include <stdio.h>
#pragma once


class Paquet {
    public:
        Paquet();
        void Shuffle();
        void Afficher();
    private:
        int paquet[52];
        int n = 0;
};
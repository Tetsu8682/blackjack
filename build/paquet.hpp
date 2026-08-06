#include <stdio.h>
#pragma once
#include <iostream>
#include <random>


class Paquet {
    public:
        Paquet();
        void Shuffle();
        void Afficher();
        int draw(void);
    private:
        int paquet[52];
        int n = 0;
        std::mt19937 seed;
        std::uniform_int_distribution<int> distrib;
};
#pragma once

#include <stdio.h>
#include <iostream>
#include <random>

/*
Gestion du paquet de carte. Pour le moment gestion simplifiée.
Constructeur : crée une liste de nombre de 1 à 52.
draw : Permet de tirer aléatoirement une carte dans le paquet
*/
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
#pragma once

#include <stdio.h>
#include <vector>

#include "paquet.hpp"

/*
Cette classe permet de gérer l'ensemble des attributs et des méthodes du croupier.
-Constructeur
-draw : Permet de piocher une carte et l'ajoute à son jeu
-afficher : Simple fonction d'affichage de son jeu
-eraseGame : Remet son jeu à 0, pour enchainer sur la prochaine partie
-getSet : Permet d'accéder à son jeu
*/

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
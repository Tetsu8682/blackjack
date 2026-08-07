#pragma once

#include <stdio.h>
#include <vector>
#include <string>

#include "paquet.hpp"

/*
Cette classe permet de gérer l'ensemble des attributs et des méthodes du joueur.
-Constructeur
-draw : Permet de piocher une carte et l'ajoute à son jeu
-afficher : Simple fonction d'affichage de son jeu
-getSet : Permet d'accéder à son jeu
-eraseGame : Remet son jeu à 0, pour enchainer sur la prochaine partie
*/

class Joueur {
    public:
        Joueur(Paquet *p, std::string n);
        void draw(void);
        void afficher(void);
        std::vector<int> getSet(void);
        void eraseGame(void);
        std::string getname(void);
    private:
        std::vector<int> set;
        Paquet* currentP;
        std::string name;
};
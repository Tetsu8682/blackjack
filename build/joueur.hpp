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
        Joueur(Paquet *p, std::string n, int a);
        void draw(void);
        void afficher(void);
        std::vector<int> getSet(void);
        void eraseGame(void);
        std::string getname(void);
        void SetBet(int bet);
        int GetBet(void);
        void SetBank(int b);
        int GetBank(void);
        void UpdateBank(int u);
    private:
        std::vector<int> set;
        Paquet* currentP;
        std::string name;
        int bet = 0;
        int bank = 0;
};
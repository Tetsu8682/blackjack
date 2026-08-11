#include "../build/paquet.hpp"
#include "../build/croupier.hpp"
#include "../build/joueur.hpp"
#include "../build/game.hpp"
#include "../build/match.hpp"

//#define DEBUG

int main(void){
    #ifdef DEBUG
        Paquet p;
        Joueur r(&p, "Romain",100);
        r.UpdateBank(-50);
        int amount = r.GetBank();
        std::cout << amount << "\n" ; 
        r.afficher();
    #else
        Paquet p;
        Croupier cas(&p);
        int joue = 1;
        Match m(cas, p);
        m.InitMatch();
        while(joue == 1){
            m.PlayGame();
            joue = m.InterMatch();
        }
    return 1;
   #endif
}
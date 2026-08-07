#include "../build/paquet.hpp"
#include "../build/croupier.hpp"
#include "../build/joueur.hpp"
#include "../build/game.hpp"
#include "../build/match.hpp"

int main(void){
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
}
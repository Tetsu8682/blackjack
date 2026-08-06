#include "../build/paquet.hpp"
#include "../build/croupier.hpp"
#include "../build/joueur.hpp"
#include "../build/game.hpp"

int main(void){
    Paquet p;
    Croupier cas(&p);
    Joueur j1(&p);
    Joueur j2(&p);
    std::vector<Joueur> players = {j1,j2};
    Game play1(players, cas);
    play1.InitialPhase();
    play1.GamePhase();
    play1.EndPhase();
   return 1;
}
#include "../build/match.hpp"

Match::Match(){
}

void Match::InitialPhase(){
    Paquet p;
    int nbjoueur;
    printf("Combien de joueur(s) prenn(ent) place?");
    scanf("%d", &nbjoueur)
    for(int i=0 ; i<nbjoueur; i++){
        Joueur j(&p);
        players.push_back(j);
    }
    Croupier crop(&p);
    croupier = &crop;
}

void Match::PlayGame(){
    Game play(players, croupier);
    play.InitialPhase();
    play.GamePhase();
    play.EndPhase();
}
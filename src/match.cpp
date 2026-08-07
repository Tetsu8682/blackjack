#include "../build/match.hpp"

Match::Match(Croupier c, Paquet p)
    :croupier(c), paquet(p)
{
}

void Match::InitMatch(){
    int nbjoueur;
    printf("Combien de joueur(s) prenn(ent) place?");
    scanf("%d", &nbjoueur);
    for(int i=0 ; i<nbjoueur; i++){
        Joueur j(&paquet);
        players.push_back(j);
    }
}

void Match::PlayGame(){
    Game play(players, croupier);
    play.InitialPhase();
    play.GamePhase();
    play.EndPhase();
}

int Match::InterMatch(){
    char a;
    printf("Est-ce que vous voulez continuer ? (y/n)");
    scanf(" %c", &a);
    if(a == 'y'){
        return 1;
    }
    else{
        return 0;
    }
}
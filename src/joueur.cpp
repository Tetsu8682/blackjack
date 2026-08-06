#include "../build/joueur.hpp"

Joueur::Joueur(Paquet* p)
    :currentP(p)
{
}

void Joueur::draw(){
    set.push_back(currentP->draw());
}

std::vector<int> Joueur::getSet(void){
    return set;
}

void Joueur::afficher(void){
    printf("Jeu du joueur : \n");
    for(int v:set){
        printf("%d  ", v);
    }
    printf("\n");
}

void Joueur::eraseGame(void){
    set.clear();
}

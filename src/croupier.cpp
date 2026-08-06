#include "../build/croupier.hpp"

Croupier::Croupier(Paquet* p)
    :currentP(p)
{
}

void Croupier::draw(void){
    set.push_back(currentP->draw());
}

void Croupier::afficher(void){
    printf("Jeu du croupier : \n");
    for(int nb:set){
        printf("%d  ", nb);
    }
    printf("\n");
}

std::vector<int> Croupier::getSet(void){
    return set;
}

void Croupier::eraseGame(void){
    set.clear();
}
#include "../build/joueur.hpp"

Joueur::Joueur(Paquet* p, std::string n)
    :currentP(p), name(n)
{
}

void Joueur::draw(){
    set.push_back(currentP->draw());
}

std::vector<int> Joueur::getSet(void){
    return set;
}

void Joueur::afficher(void){
    std::cout << "Jeu de" <<  name << " : \n";
    for(int v:set){
        printf("%d  ", v);
    }
    printf("\n");
}

void Joueur::eraseGame(void){
    set.clear();
}

std::string Joueur::getname(void){
    return name;
}

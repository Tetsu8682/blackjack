#include "../build/joueur.hpp"

Joueur::Joueur(Paquet* p, std::string n, int a)
    :currentP(p), name(n), bank(a)
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

void Joueur::SetBet(int bet){
    this->bet = bet;
}

int Joueur::GetBet(void){
    return bet;
}

int Joueur::GetBank(void){
    return bank;
}

void Joueur::UpdateBank(int u){
    bank += u;
}
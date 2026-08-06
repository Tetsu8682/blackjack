#include "../build/paquet.hpp"

Paquet::Paquet(){
    for(int i =0; i<52; i++){
        paquet[i] = i;
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    seed = gen;
    std::uniform_int_distribution<int> exdistrib(0,51);
    distrib = exdistrib;
}

void Paquet::Afficher(){
    for (int i = 0; i<52; i++){
        printf("%d ", paquet[i]);
    }
    printf("\n");
}

int Paquet::draw(void){
    return distrib(seed);
}
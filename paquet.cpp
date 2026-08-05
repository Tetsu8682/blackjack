#include "paquet.hpp"

Paquet::Paquet(){
    for(int i =0; i<52; i++){
        paquet[i] = i;
    }
}

void Paquet::Afficher(){
    for (int i = 0; i<52; i++){
        printf("%d ", paquet[i]);
    }
    printf("\n");
}

int main(void){
    Paquet p;
    p.Afficher();
    return 1;
}
#include "../build/game.hpp"

Game::Game(std::vector<Joueur>& ps, Croupier c)
    :players(ps), croupier(c)
{
}


int Game::calculValue(std::vector<int> game){
    int value = 0;
    for(int v:game){
        int ivalue = ((v/4)+1 );
        if(ivalue == 1){
            value += 11;
        }
        else if(ivalue >= 10){
            value += 10;
        }
        else{
            value += ivalue;
        }
    }
    return value;
}

void Game::printGame(std::vector<int> game){
    int value = calculValue(game);
    for(int v: game){
        printf("%d  ", v);
    }
    printf("\n");
    printf("Set value : %d \n", value);
}

void Game::InitialPhase(void){
    printf("Phase initial : \n");
    int i = 1;
    for(Joueur& j:players){
        j.draw();
        j.draw();
        printf("Jeu du joueur %d : ", i);
        printGame(j.getSet());
        i++;
    }
    croupier.draw();
    croupier.draw();
    printf("Jeu du croupier : ");
    printGame(croupier.getSet());
}

void Game::GamePhase(void){
    int i = 1;
    printf("Phase de jeu : \n");
    for(Joueur& j:players){
        char a;
        printf("Joueur %d \n", i);
        printGame(j.getSet());
        printf("Voulez-vous piocher une carte ? (y/n) \n");
        scanf(" %c", &a);
        while(a == 'y'){
            j.draw();
            printGame(j.getSet());
            printf("Voulez-vous piocher une carte ? (y/n) \n");
            scanf(" %c", &a);
        }
        i++;
    }
    printf("Au tour du croupier. \n");
    int valuec = calculValue(croupier.getSet());
    while(valuec < 18){
        croupier.draw();
        valuec = calculValue(croupier.getSet());
    }
}

void Game::EndPhase(void){
    int i = 1;
    int valuec = calculValue(croupier.getSet());
    printf("Résultat croupier : %d \n", valuec);
    for(Joueur& j: players){
        int valuej = calculValue(j.getSet());
        printf("Résultat Joueur %d : %d \n", i, valuej);
        if(valuej > 21){
            printf("Le joueur %d a perdu car il a dépassé 21. \n",i);
        }
        else if(valuec > 21){
            printf("Tous les joueurs en-dessous de 21 ont gagné. Donc le joueur %d gagne \n", i);
        }
        else{
            if(valuej > valuec){
                printf("Le joueur %d a gagné. \n", i);
            }
            else if(valuej == valuec){
                printf("Le joueur %d fait égalité avec le croupier. \n", i);
            }
            else{
                printf("Le joueur %d a perdu. \n", i);
            }
        }
        i ++;
    }
}
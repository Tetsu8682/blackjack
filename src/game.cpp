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
        std::cout << "Jeu de " << j.getname() << " : \n";
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
        std::cout << "Joueur : " << j.getname() << "\n";
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
        std::cout << "Résultat Joueur : "  << j.getname() << " -> " << valuej << "\n" ;
        if(valuej > 21){
            std::cout <<  j.getname() <<  " a perdu car il a dépassé 21. \n";
        }
        else if(valuec > 21){
            std::cout << "Tous les joueurs en-dessous de 21 ont gagné. " << j.getname() << " a donc gagné. \n";
        }
        else{
            if(valuej > valuec){
                std::cout << j.getname() << "a gagné. \n";
            }
            else if(valuej == valuec){
                std::cout <<  j.getname() << " a fait égalité avec le croupier. \n";
            }
            else{
                std::cout <<  j.getname() <<" a perdu. \n";
            }
        }
        i ++;
    }
}
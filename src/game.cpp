#include "../build/game.hpp"

Game::Game(std::vector<Joueur>& ps, Croupier c)
    :players(ps), croupier(c)
{
}


int Game::calculValue(std::vector<int> game){
    int value = 0;
    int as = 0;
    for(int v:game){
        int ivalue = ((v/4)+1 );
        if(ivalue == 1){
            value += 11;
            as = 1;
        }
        else if(ivalue >= 10){
            value += 10;
        }
        else{
            value += ivalue;
        }
    }
    if(as == 1 ){
        if(value > 21){
            value -= 10;
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
        //Bank time
        int bank = j.GetBank();
        std::cout << "Montant de la banque de "<< j.getname() << " : " << bank <<"\n";
        //Bet time
        int bet = 0;
        std::cout << "Mise de "<< j.getname() << " : \n";
        scanf("%d", &bet);
        j.SetBet(bet);
        //Draw time
        j.draw();
        j.draw();
        //Print time
        std::cout << "Jeu de " << j.getname() << " : \n";
        printGame(j.getSet());
        printf("Mise : %d \n", j.GetBet());
        i++;
    }
    croupier.draw();
    croupier.draw();
    printf("Jeu du croupier : ");
    printGame(croupier.getSet());
}

void Game::GamePhase(void){
    //Players time
    int i = 1;
    printf("Phase de jeu : \n");
    for(Joueur& j:players){
        char a;
        //Print time
        std::cout << "Joueur : " << j.getname() << "\n";
        printGame(j.getSet());
        printf("Mise : %d \n", j.GetBet());
        //Play time
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
    //Croupier time
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
        int bet = j.GetBet();
        if(valuej > 21){
            std::cout <<  j.getname() <<  " a perdu car il a dépassé 21. \n";
            std::cout << "Mise Perdue :" << bet << "\n";
            j.UpdateBank(-bet);
        }
        else if(valuec > 21){
            std::cout << "Tous les joueurs en-dessous de 21 ont gagné. " << j.getname() << " a donc gagné. \n";
            std::cout << "Gain : " << bet << "\n";
            j.UpdateBank(bet);
        }
        else{
            if(valuej > valuec){
                std::cout << j.getname() << "a gagné. \n";
                std::cout << "Gain : " << bet << "\n";
                j.UpdateBank(bet);
            }
            else if(valuej == valuec){
                std::cout <<  j.getname() << " a fait égalité avec le croupier. Il récupère sa mise\n";
                std::cout << "Gain : 0€" << "\n";
            }
            else{
                std::cout <<  j.getname() <<" a perdu. \n";
                std::cout << "Mise Perdue :" << bet << "\n";
                j.UpdateBank(-bet);
            }
        }
        i ++;
        j.eraseGame();
    }
}
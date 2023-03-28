#include "game.hpp"
#include <cstdlib>
#include <string>


ariel::Game::Game(Player p1, Player p2){
    /* this->m_p1 = p1;
    this->m_p2 = p2;
    this->makeDeck();
    this->splitDeck(m_p1, m_p2);
    this->gameLog = makeLog();
    this->statistics = makeStats();
    this->gamepotpts = 0;
    this->flagEnded = 0; */
    this->statistics = makeStats();
}

ariel::plog* ariel::Game::makeLog(){

        /* plog* gameLog = new plog;
        gameLog->next = nullptr;
        gameLog->logs = "";
        this->gameLogHead = gameLog;
        
        return gameLog; */
        return nullptr;
}
ariel::stats* ariel::Game::makeStats(){
        stats* gameStats = new stats;
        gameStats->drawRate = 0.0;
        gameStats->draws = 0;
        gameStats->p1cardsWon = 0;
        gameStats->p2cardsWon = 0;
        gameStats->p1WinRate = 0.0;
        gameStats->p2WinRate = 0.0;
        gameStats->turns = 0;
        
        return gameStats; 
}

void ariel::Game::makeDeck(){
        /* Card* cards = new Card[52];
        this->m_gamepot.cards = &cards[0];
        int size = 52;
        int i=0;
        for(int k = ACE; k!=LASTVAL; k++){
                for(int j = CLUBS; j!=LASTSYMB; j++){

                        cards[i].setCard(static_cast<val>(k), static_cast<symb>(j));
                        i++;
                }
        }
        i = 0;
        for(int k = ACE; k!=LASTVAL; k++){
                for(int j = CLUBS; j!=LASTSYMB; j++){

                        i++;
                }
        }
        

        from geeks .com
        for (int i=0; i<52 ;i++){
                 Random for remaining positions.
                int r = i + (rand() % (52 -i));
 
                swap(cards[i], cards[r]);
        }

        
        m_gamepot.size = size;
        m_gamepot.index = 0; */

}

void ariel::Game::splitDeck(Player p1, Player p2){
        /* m_p1.m_stack.cards = &m_gamepot.cards[0];
        m_p2.m_stack.cards = &m_gamepot.cards[0];
        m_p1.m_stack.index = 0;
        m_p2.m_stack.index = 51;
        m_p1.m_stack.size = 26;
        m_p2.m_stack.size = 26; */
}

ariel::Player ariel::Game::getP1(){
        return this->m_p1; 
}
ariel::Player ariel::Game::getP2(){
        return this->m_p2; 
}

ariel::stats* ariel::Game::getStats(){
        return this->statistics; 
}

void ariel::Game::setGame(Player p1, Player p2){
        //creates game instance with p1 and p2
        //creates card deck and shuffles
        //points p1 and p2 pstacks to games pstack
};

std::string ariel::Game::makeLogMsg(int func, Card c1, Card c2){
        /* std::string Str = "";
        if(func == 0){
                Str += m_p1.getPlayerName() + " played " + c1.to_string() + " " + m_p2.getPlayerName() + " played " + c2.to_string()+". draw. ";
        }else if(func == 1){
                Str += m_p1.getPlayerName() + " played " + c1.to_string() + " " + m_p2.getPlayerName() + " played " + c2.to_string()+". "+m_p1.getPlayerName() +" Wins.";
        }else{
                Str += m_p1.getPlayerName() + " played " + c1.to_string() + " " + m_p2.getPlayerName() + " played " + c2.to_string()+". "+m_p2.getPlayerName() +" Wins.";
        }
        return Str; */
        return "";
        
}

void ariel::Game::updateStats(int winner, int gamePts, int turns){
        /* this->getStats()->turns+=turns;
        this->getStats()->drawRate = (double)this->getStats()->draws/(double)this->getStats()->turns;

        if(winner == 1){
                this->getStats()->p1cardsWon+=gamePts;
                this->getStats()->p1WinRate = m_p1.cardesTaken()/this->getStats()->turns;
        }else{
                this->getStats()->p2cardsWon+=gamePts;
                this->getStats()->p2WinRate = m_p2.cardesTaken()/this->getStats()->turns;
        } */
        
}

void ariel::Game::playTurn(){
        /* if(this->flagEnded==1){
                return;
        }
        pop pstack of p1 and p2
        Card c1, c2;
        c1 = m_p1.getPlayerDeck().cards[m_p1.getPlayerIndex()];
        c2 = m_p2.getPlayerDeck().cards[m_p2.getPlayerIndex()];

        
        std::string logStr = "";
         Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
         Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
        while(compCard(c1, c2)== 0 && m_p2.getPlayerDeck().size > 2){
                
                logStr += makeLogMsg(compCard(c1, c2), c1, c2);
                m_p1.increasePlayerIndex(2);
                m_p2.increasePlayerIndex(-2);
                m_p1.increasePlayerSize(-2);
                m_p2.increasePlayerSize(-2);

                c1 = m_p1.getPlayerDeck().cards[m_p1.getPlayerDeck().index];
                c2 = m_p2.getPlayerDeck().cards[m_p2.getPlayerDeck().index];
                this->gamepotpts += 4;
                this->statistics->draws++;
        }

        if(m_p2.getPlayerDeck().size == 2 || m_p2.getPlayerDeck().size == 1 || m_p2.getPlayerDeck().size == 0){
                if(compCard(c1,c2)==0){
                        
                        logStr += makeLogMsg(compCard(c1, c2), c1, c2);
                        this->statistics->draws++;
                        this->gamepotpts+=2;
                        m_p1.addmPoints(1);
                        m_p2.addmPoints(1);
                }else if(compCard(c1,c2)==1){
                        
                        logStr += makeLogMsg(compCard(c1, c2), c1, c2);
                        this->gamepotpts+=2;
                        m_p1.addmPoints(gamepotpts);
                }else{
                        
                        logStr += makeLogMsg(compCard(c1, c2), c1, c2);
                        this->gamepotpts+=2;
                        m_p2.addmPoints(gamepotpts);
                }

                updateStats(compCard(c1,c2), gamepotpts, 1);
                this->gamepotpts = 0;
                this->flagEnded = 1;

                this->gameLog->logs += logStr;
                plog* nxt = new plog;
                this->gameLog->next = nxt;
                this->gameLog->next->next = nullptr;
                this->gameLog = nxt;
                return;
        }
        

        m_p1.increasePlayerIndex(1);
        m_p2.increasePlayerIndex(-1);
        m_p1.increasePlayerSize(-1);
        m_p2.increasePlayerSize(-1);
        
        this->gamepotpts += 2;

        
        if(compCard(c1,c2 )==1){
                //logStr += m_p1.getPlayerName() + " played " + c1.to_string() + " " + m_p2.getPlayerName() + " played " + c2.to_string()+". "+m_p1.getPlayerName() +" Wins.";
                logStr += makeLogMsg(compCard(c1, c2), c1, c2);
                m_p1.addmPoints(gamepotpts);
        }else{
                //logStr += m_p1.getPlayerName() + " played " + c1.to_string() + " " + m_p2.getPlayerName() + " played " + c2.to_string()+". "+m_p2.getPlayerName() +" Wins.";
                logStr += makeLogMsg(compCard(c1, c2), c1, c2);
                m_p2.addmPoints(gamepotpts);
        }

        updateStats(compCard(c1,c2), gamepotpts, 1);

        //std::cout << "HERE" <<std::endl;
        this->gameLog->logs += logStr;
        plog* nxt = new plog;
        this->gameLog->next = nxt;
        this->gameLog->next->next = nullptr;
        this->gameLog = nxt;

        //std::cout << "HERE" <<std::endl;
        this->gamepotpts = 0;
        return;

        //compare cards
        //if winner: push to plog info, increment winner points
        //if draw: push to plog info, double pop stack , try winner
        //if cards all finished and still draw split game pot. */
    };

void ariel::Game::printLastTurn(){
        /* plog* temp = this->gameLogHead;
        while(temp->next!=nullptr){
                temp = temp->next;
        }
        std::cout << temp->logs << std::endl; */
};

void ariel::Game::playAll(){
        /* //runs play turn untill no more cards
        while(this->flagEnded!=1){
                playTurn();
        } */
};

void ariel::Game::printWiner(){
        /* //prints winner (playetr with highest points)
        if(getP1().cardesTaken() == getP2().cardesTaken()){
                std::cout << "Draw." << std::endl;
        }else if(getP1().cardesTaken() > getP2().cardesTaken()){
                //p1 wins
                std::cout << "Player one wins" << std::endl;
        }else{
                //p2 wins
                std::cout << "Player two wins" << std::endl;
        } */
};

void ariel::Game::printLog(){
       /*  //prints the log list
        plog* temp = this->gameLogHead;
        while(temp->next!=nullptr){
                std::cout << temp->logs << std::endl;
                temp = temp->next;
        } */
};

void ariel::Game::printStats(){
        //for each player prints basic statistics: 
        //win rate, cards won, <other stats you want to print>. 
        //Also print the draw rate and amount of draws that happand. 
        //(draw within a draw counts as 2 draws. )
};

int ariel::Game::compCard(Card c1, Card c2){
    /* if(c1.getIntValue() == c2.getIntValue()){
        return 0; // flag as a draw
    }else if(c1.getIntValue() > c2.getIntValue())
        return 1;
    else{
        return -1;
    } */
    return 0;
}
#pragma once
#include "player.hpp"
#include "card.hpp"
#include <string>

namespace ariel{
typedef struct stats{
    double p2WinRate,p1WinRate, drawRate;
    int p1cardsWon, p2cardsWon, draws, turns;

}stats;

typedef struct plog{
    std::string logs;
    plog *next;
}plog;

class Game{
    private:
        Player m_p1, m_p2;
        pstack m_gamepot;
        plog *gameLog = nullptr, *gameLogHead = nullptr;
        stats *statistics = nullptr;
        int gamepotpts;
        int flagEnded;

        void makeDeck();
        void splitDeck(Player plyr1, Player plyr2);
        ariel::plog* makeLog();
        ariel::stats* makeStats();

    public:
    
    Game(Player plyr1, Player plyr2);
    
    ~Game(){
        if((statistics) != NULL){
            delete statistics;
        }
    }

    Player getP1();
    Player getP2();
    stats *getStats();
    plog *getPlog();

    void setGame(Player plyr1, Player plyr2);
        //creates game instance with p1 and p2
        //creates card deck and shuffles
        //points p1 and p2 pstacks to games pstack
    

    void playTurn();
        //pop pstack of p1 and p2
        //compare cards
        //if winner: push to plog info, increment winner points
        //if draw: push to plog info, double pop stack , try winner
        //if cards all finished and still draw split game pot.
    

    void printLastTurn();
        //prints plog last turn (peek stack)
    

    void playAll();
        //runs play turn untill no more cards
    

    void printWiner();
        //prints winner (playetr with highest points)
    

    void printLog();
        //prints the log stack in reverse
    

    void printStats();
        //for each player prints basic statistics: 
        //win rate, cards won, <other stats you want to print>. 
        //Also print the draw rate and amount of draws that happand. 
        //(draw within a draw counts as 2 draws. )
    
    int compCard(Card card1, Card card2);

    std::string makeLogMsg(int func, Card card1, Card card2);

    void updateStats(int winner, int gamePts, int turns);
};
}
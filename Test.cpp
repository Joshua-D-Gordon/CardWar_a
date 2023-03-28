#include "doctest.h"
#include "card.hpp"
#include "game.hpp"
#include "player.hpp"
#include <string.h>

namespace ariel{

/* Player p1("Joshua");
Player p2("Lahan");
Game game(p1,p2); */

//player.playturn()
//game.printlastturn()
//player.stacksize()
//player.cardstaken()
//game.playall()
//game.printwinerlog()
//game.printlog()
//game.printstatus()

TEST_CASE("Initilize Game Checks") { // starting cases
    Player p1("Joshua");
    Player p2("Lahan");
    Game game(p1,p2);

    CHECK( p1.cardesTaken() == 0);
    CHECK( p2.cardesTaken() == 0);
    CHECK( p1.stacksize() == 26);
    CHECK( p2.stacksize() == 26);
    CHECK(game.getStats()->draws == 0);
    CHECK(game.getStats()->p1cardsWon == 0);
    CHECK(game.getStats()->p2cardsWon == 0);
    CHECK(game.getStats()->turns == 0);
    CHECK(game.getStats()->drawRate == 0);
    CHECK(game.getStats()->p1WinRate == 0);
    CHECK(game.getStats()->p2WinRate == 0);
    CHECK(game.getStats()->turns == 0);

    
}

TEST_CASE("One player per game") { // one player per game test
    Player p1("Joshua");
    Player p2("Lahan");
    Game game(p1,p2);
    Player p3("intruder");
    CHECK_THROWS(Game(p1,p3));
    CHECK_THROWS(Game(p3,p2));
    CHECK_THROWS(Game(p1,p2));
}

TEST_CASE("Shuffel test") { // starting cases shuffeled deck  - "fairness test" - "95%"
    //note this dose not represent a acctual shuffle check but rather a fairness check that each player has an eqaul chance of winning any given game
    int PoneWins = 0;
    double epsilon = 0.05, delta = 0.05, p = 1/52;
    int nbase = ((1)/2*(epsilon*epsilon)*(delta));
    nbase+=1; // n > 1/2*epsilon^2 * delta
    //based on chebyshev's inequality - הסתברות 2 הרצאה 1
    for(int i = 0; i<nbase; i++){
        Player ps1("one");
        Player ps2("Two");
        Game games(ps1, ps2);
        games.playAll();
        if(games.getStats()->p1cardsWon > games.getStats()->p2cardsWon){
            PoneWins++;
        }
    }
    double q = PoneWins/nbase;
    double absPQ = 0;
    if((q-p)<0){
        absPQ = p - q;
    }else{
        absPQ = q - p;
    }
    CHECK(absPQ < epsilon); // 95% accuracy --> 1- delta
}

TEST_CASE("Initilize Game Checks") { // starting cases for functions
    Player p1("Joshua");
    Player p2("Lahan");
    Game game(p1,p2);
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLog());
}


TEST_CASE("Check after turn") { // after turn case
    Player p1("Joshua");
    Player p2("Lahan");
    Game game(p1,p2);
    game.playTurn();

    CHECK( p1.cardesTaken() + p2.cardesTaken() > 0);
    CHECK( p1.stacksize() < 26);
    CHECK( p2.stacksize() < 26);
    CHECK(game.getStats()->draws >= 0);
    CHECK(game.getStats()->p1cardsWon + game.getStats()->p2cardsWon == p1.cardesTaken() + p2.cardesTaken());
    CHECK(game.getStats()->turns == 1);
    CHECK(game.getStats()->drawRate == 0);
    CHECK(game.getStats()->p1WinRate + game.getStats()->p2WinRate == 1);

    
    if(game.getStats()->p1cardsWon + game.getStats()->p2cardsWon != 52){ // game has not ended
    
        CHECK_NOTHROW(game.printWiner());
    }
    
    
}

TEST_CASE("Check end game") { // after end game case's
    Player p1("Joshua");
    Player p2("Lahan");
    Game game(p1,p2);

    game.playAll();
    CHECK( p1.cardesTaken() + p2.cardesTaken() == 52);
    if(game.getStats()->p1WinRate == game.getStats()->p2WinRate){
        CHECK_NOTHROW(game.printWiner());
        CHECK(game.getStats()->p1cardsWon == game.getStats()->p2cardsWon);
    }
    
    CHECK(game.getP1().m_stack.size == 0);
    CHECK(game.getP2().m_stack.size == 0);
    
    CHECK(game.getStats()->turns >= 1);
    
    CHECK(game.getStats()->p1WinRate + game.getStats()->p2WinRate >= 0);
    
}

}
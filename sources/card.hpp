#pragma once
#include <iostream>
#include <string>

namespace ariel{

typedef enum val{
    ACE=1, TWO, THREE ,FOUR, FIVE ,SIX, SEVEN , EIGHT, NINE, TEN, JACK, QUEEN, KING, LASTVAL                   
}val;
typedef enum symb{
    CLUBS = 1, DIAMONDS, HEARTS, SPADES, LASTSYMB
}symb;

class Card{
    private:
        val m_value;
        symb m_symbol;

    public:
    Card();
    Card(val val, symb symb);
    
    void setCard(val m_val, symb m_symb);

    val getVal();

    int getIntValue() const;
    
    int getS();

    symb getSymb();

    static int comp(Card card1, Card card2);

    std::string to_string();
};

}
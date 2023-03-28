#include "card.hpp"
#include <iostream>
#include <string>

ariel::Card::Card(){
    //this->m_value = LASTVAL;
    //this->m_symbol = LASTSYMB;
}

ariel::Card::Card(val v, symb s){
    //this->m_value = v;
    //this->m_symbol = s;
}

void ariel::Card::setCard(val m_v, symb m_s){
    //this->m_value = m_v;
    //this->m_symbol = m_s;
};

ariel::val ariel::Card::getVal(){return m_value;}

int ariel::Card::getIntValue() const {
    //int intValue = static_cast<int>(m_value);
    
    //return intValue;
    return 0;
} 
int ariel::Card::getS(){
    //return (symb)this->m_symbol;
    return 0;
}

ariel::symb ariel::Card::getSymb(){
    return m_symbol;
}

std::string ariel::Card::to_string() {
    /* std::string numberStr;
    switch(m_value) {
        case ACE: numberStr = "Ace"; break;
        case TWO: numberStr = "Two"; break;
        case THREE: numberStr = "Three"; break;
        case FOUR: numberStr = "Four"; break;
        case FIVE: numberStr = "Five"; break;
        case SIX: numberStr = "Six"; break;
        case SEVEN: numberStr = "Seven"; break;
        case EIGHT: numberStr = "Eight"; break;
        case NINE: numberStr = "Nine"; break;
        case TEN: numberStr = "Ten"; break;
        case JACK: numberStr = "Jack"; break;
        case QUEEN: numberStr = "Queen"; break;
        case KING: numberStr = "King"; break;
        default: numberStr = "Unknown Number"; break;
    }

    std::string symbolStr;
    switch(m_symbol) {
        case CLUBS: symbolStr = "Clubs"; break;
        case DIAMONDS: symbolStr = "Diamonds"; break;
        case HEARTS: symbolStr = "Hearts"; break;
        case SPADES: symbolStr = "Spades"; break;
        default: symbolStr = "Unknown Symbol"; break;
    }

    return numberStr + " of " + symbolStr; */
    return "";
}

static int comp(ariel::Card c1, ariel::Card c2){
    /* if(c1.getVal() == c2.getVal()){
        return 0;
    }
    if(c1.getVal()>c2.getVal()){
        return 1;
    }else{
        return -1;
    } */
    return 0;
} 
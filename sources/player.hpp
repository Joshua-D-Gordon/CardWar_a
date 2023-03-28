#pragma once
#include "card.hpp"
#include <string>
#include <iostream>

namespace ariel{

typedef struct pstack
{
    int size = 0, index = 0;
    Card *cards = nullptr;

    
}pstack;


class Player{

    private:
        const char* m_name;
        int m_points;

    public:
    pstack m_stack;
    Player();
    Player(const char* m_name);

    void setPlayerDeck(pstack pdeck, int index, int size);
    void increasePlayerIndex(int index);
    void increasePlayerSize(int size);

    void addmPoints(int pts){
        this->m_points+=pts;
    }
    pstack getPlayerDeck();

    int getPlayerIndex();

    std::string getPlayerName();

    int stacksize();

    int cardesTaken();

};
}
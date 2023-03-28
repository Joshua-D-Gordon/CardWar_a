#include "player.hpp"
#include <string>
ariel::Player::Player(const char* name){
    /* this->m_name = name;
    //this->m_stack = nullptr;
    this->m_points = 0;
 */
}

ariel::Player::Player(){
    /* this->m_name = "";
    //this->m_stack;
    this->m_points = 0; */
}

ariel::pstack ariel::Player::getPlayerDeck(){
    return this->m_stack; 
}
void ariel::Player::increasePlayerIndex(int index){
    /* this->m_stack.index += index;  */
}
int ariel::Player::getPlayerIndex(){
    /* return this->m_stack.index; */
    return 0;
}
void ariel::Player::increasePlayerSize(int size){
    /* this->m_stack.size += size; */
}

std::string ariel::Player::getPlayerName(){
    /* return this->m_name; */
    return "";
}

void ariel::Player::setPlayerDeck(pstack pdeck, int index, int size){
    //this->m_stack = pdeck;
    //this->m_stack.index = index;
    //this->m_stack.size = size;
}

int ariel::Player::stacksize(){
    /* return this->m_stack.size; */
    return 0;
}

int ariel::Player::cardesTaken(){
    /* return this->m_points; */
    return 0;
}





#include "lifeAbility.h"
#include "board.h"
#include <string>

using namespace std;

void LifeAbility::activate(Board *board) override{
  board->changeLife(player, amount);

void LifeAbility::newAmount(int amount){
  this->amount = amount;
}

LifeAbility::LifeAbility(std::string description, int cost, int amount, 
                         int player):
  description{description}, cost{cost}, amount{amount}, player{player} { }

#include "disableAbility.h"
#include "board.h"
#include <string>

using namespace std;

void DisableAbility::activate(Board *board) override{
  board->removeAbility(player, slot);
}

void DisableAbility::changeTarget(int player, int slot){
  this->player = player;
  this->slot = slot;
}

DisableAbility::DisableAbility(std::string description, int cost, int player, 
                               int slot):
  description{description}, cost{cost}, player{player}, slot{slot} { }

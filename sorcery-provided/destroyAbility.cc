#include "destroyAbility.h"
#include "board.h"
#include <string>

using namespace std;

void DestroyAbility::activate(Board *board) override{
  board->destroy(player, slot);

void DestroyAbility::changeTarget(int player, int slot){
  this->player = player;
  this->slot = slot;
}

DestroyAbility::DestroyAbility(string description, int cost, int player, 
                               int slot):
  description{description}, cost{cost}, player{player}, slot{slot} { }

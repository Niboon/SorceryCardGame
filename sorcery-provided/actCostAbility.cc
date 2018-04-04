#include "actCostAbility.h"
#include "board.h"
#include <string>

using namespace std;

void ActCostAbility::activate(Board *board) override{
  board->abilityChangeCost(player, slot, costMod);
}

void ActCostAbility::changeCost(int newCost){
  costMod = newCost;
}

void ActCostAbility::changeTarget(int player, int slot){
  this->player = player;
  this->slot = slot;
}

ActCostAbility::ActCostAbility(string description, int cost, int player, 
                               int slot, int costMod):
  description{description}, cost{cost}, player{player}, slot{slot}, costMod{costMod} { }


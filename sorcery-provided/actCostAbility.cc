#include "actCostAbility.h"
#include "board.h"

void ActCostAbility::activate(Board *board) override{
  board->abilityChangeCost(player, slot, costMod);
}

ActCostAbility::ActCostAbility(int player, int slot, int costMod):
  player{player}, slot{slot}, costMod{costMod} { }


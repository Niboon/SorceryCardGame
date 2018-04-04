#include "disableAbility.h"
#include "board.h"

void DisableAbility::activate(Board *board) override{
  board->removeAbility(player, slot);
}

DisableAbility::DisableAbility(int player, int slot):
  player{player}, slot{slot} { }

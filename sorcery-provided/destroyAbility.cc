#include "destroyAbility.h"
#include "board.h"

void DestroyAbility::activate(Board *board) override{
  board->destroy(player, slot);

DestroyAbility::DestroyAbility(int player, int slot):
  player{player}, slot{slot} { }

#include "returnAbility.h"
#include "board.h"

void ReturnAbility::activate(Board *board) override{
  board->returnToDeck(player, slot);
};

ReturnAbility::ReturnAbility(int player, int slot):
  player{player}, slot{slot} { }

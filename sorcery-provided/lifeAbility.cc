#include "lifeAbility.h"
#include "board.h"

void LifeAbility::activate(Board *board) override{
  board->changeLife(player, amount);
}

LifeAbility::LifeAbility(int amount, int player):
  amount{amount}, player{player} { }

#include "manaAbility.h"
#include "board.h"

void ManaAbility::activate(Board *board) override{
  board->changeMagic(player, manaBonus);
}

ManaAbility::ManaAbility(int player, int mana):
  player{player}, manaBonus{mana} { }

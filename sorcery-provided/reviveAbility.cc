#include "reviveAbility.h"
#include "board.h"

void ReviveAbility::activate(Board *board) override{
  board->resurrect(player);
}

ReviveAbility::ReviveAbility(int player): player{player} { }

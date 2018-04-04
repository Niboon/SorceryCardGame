#include "changeAbility.h"
#include "board.h"

void ChangeAbility::activate(Board *board) override{
  if (allMinions){
    for (int i = 1; i <= board->getNumMinions(player); i++){
      board->changeDef(player, amount, i);
    }
  }
  else{
    board->changeDef(player, amount, slot);
  }
}

ChangeAbility::ChangeAbility(int amount, int player, int slot, bool allMinions):
  amount{amount}, player{player}, slot{slot}, allMinions{allMinions} { }

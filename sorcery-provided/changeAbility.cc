#include "changeAbility.h"
#include "board.h"
#include <string>

using namespace std;

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

void ChangeAbility::newTarget(int player, int slot, bool allMinions){
  this->player = player;
  this->slot = slot;
  this->allMinions = allMinions;
}

void ChangeAbility::newAmount(int amount){
  this->amount = amount;
}

ChangeAbility::ChangeAbility(string description, int cost, int amount, 
                             int player, int slot, bool allMinions):
  description{decription}, cost{cost}, amount{amount}, player{player}, 
  slot{slot}, allMinions{allMinions} { }

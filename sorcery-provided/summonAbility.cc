#include "summonAbility.h"
#include "board.h"

void SummonAbility::activate(Board *board) override{
  board->specialSummon(player, name, numSummons);
}

SummonAbility::SummonAbility(std::string name, int player, 
                             int numSummons=1):
  name{name}, player{player}, summons{summons} { }

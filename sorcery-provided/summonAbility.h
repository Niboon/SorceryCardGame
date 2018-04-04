#ifndef SUMMONABILITY_H
#define SUMMONABILITY_H

#include <string>
#include "abilityImpl.h"

class SummonAbility : public abilityImpl{
  int player;
  int attack;
  int defence;
  int numSummons;
  std::string summonName;
  public:
  void activate(Board *board) override;
  void changeStats(int attack, int defence, int numSummons);
  SummonAbility(std::string description, int cost, std::string name, int player,
                int attack=1, int defence=1, int numSummons=1);
}

#endif

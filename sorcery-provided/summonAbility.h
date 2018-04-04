#ifndef SUMMONABILITY_H
#define SUMMONABILITY_H

#include <string>
#include "ability.h"

struct SummonAbility : public Ability::AbilityType{
  int player;
  int numSummons;
  std::string summonName;
  void activate(Board *board) override;
  SummonAbility(std::string name, int player, int numSummons=1);
}

#endif

#ifndef ACTCOSTABILITY_H
#define ACTCOSTABILITY_H

#include "ability.h"

struct ActCostAbility : public Ability::AbilityType{
  int player;
  int slot;
  int costMod;
  void activate(Board *board) override;
  ActCostAbility(int player, int slot, int costMod);
}

#endif

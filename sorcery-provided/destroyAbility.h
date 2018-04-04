#ifndef DESTROYABILITY_H
#define DESTROYABILITY_H

#include "ability.h"

struct DestroyAbility : public Ability::AbilityType{
  int player;
  int slot;
  void activate(Board *board) override;
  DestroyAbility(int player, int slot);
}

#endif

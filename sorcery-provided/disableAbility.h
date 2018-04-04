#ifndef DISABLEABILITY_H
#define DISABLEABILITY_H

#include "ability.h"

struct DisableAbility : public Ability::AbilityType{
  int player;
  int slot;
  void activate(Board *board) override;
  DisableAbility(int player, int slot);
}

#endif

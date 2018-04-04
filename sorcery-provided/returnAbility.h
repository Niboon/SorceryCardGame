#ifndef RETURNABILITY_H
#define RETURNABILITY_H

#include "ability.h"

struct ReturnAbility : public Ability::AbilityType{
  int player;
  int slot;
  void activate(Board *board) override;
  ReturnAbility(int player, int slot);
}

#endif

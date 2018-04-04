#ifndef REVIVEABILITY_H
#define REVIVEABILITY_H

#include "ability.h"

struct ReviveAbility : public Ability::AbilityType{
  int player;
  void activate(Board *board) override;
  ReviveAbility(int player);
}

#endif

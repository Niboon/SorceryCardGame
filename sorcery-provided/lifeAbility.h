#ifndef LIFEABILITY_H
#define LIFEABILITY_H

#include "ability.h"

struct LifeAbility : public Ability::AbilityType {
  int amount;
  int player;
  void activate(Board *board) override;
  ChangeAbility(int amount, int player);
};

#endif

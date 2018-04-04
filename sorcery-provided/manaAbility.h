#ifndef MANAABILITY_H
#define MANAABILITY_H

#include "ability.h"

struct ManaAbility : public Ability::AbilityType{
  int player;
  int manaBonus;
  void activate(Board *board) override;
  ManaAbility(int player, int mana);
}

#endif

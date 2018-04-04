#ifndef CHANGEABILITY_H
#define CHANGEABILITY_H

#include "ability.h"

struct ChangeAbility : public Ability::AbilityType {
  int amount;
  int player;
  int slot;
  bool allMinions;
  void activate(Board *board) override;
  ChangeAbility(int amount, int player, int slot, bool allMinions);
};

#endif

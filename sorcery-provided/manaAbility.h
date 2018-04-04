#ifndef MANAABILITY_H
#define MANAABILITY_H

#include "abilityImpl.h"

class ManaAbility : public abilityImpl{
  int player;
  int manaBonus;
  public:
  void activate(Board *board) override;
  void changeMana(int mana);
  void changeTarget(int player);
  ManaAbility(std::string description, int cost, int player, int mana);
}

#endif

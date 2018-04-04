#ifndef LIFEABILITY_H
#define LIFEABILITY_H

#include "abilityImpl.h"

class LifeAbility : public abilityImpl {
  int amount;
  int player;
  public:
  void activate(Board *board) override;
  void newAmount(int amount);
  ChangeAbility(std::string description, int cost, int amount, int player);
};

#endif

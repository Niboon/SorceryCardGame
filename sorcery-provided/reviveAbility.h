#ifndef REVIVEABILITY_H
#define REVIVEABILITY_H

#include "abilityImpl.h"

class ReviveAbility : public abilityImpl{
  int player;
  public:
  void activate(Board *board) override;
  ReviveAbility(std::string description, int cost, int player);
}

#endif

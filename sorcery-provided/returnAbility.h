#ifndef RETURNABILITY_H
#define RETURNABILITY_H

#include "abilityImpl.h"

class ReturnAbility : public abilityImpl{
  int player;
  int slot;
  public:
  void activate(Board) override;
  void changeTarget(int player, int slot);
  ReturnAbility(std::string description, int cost, int player, int slot);
}

#endif

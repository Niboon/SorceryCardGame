#ifndef DESTROYABILITY_H
#define DESTROYABILITY_H

#include "abilityImpl.h"

class DestroyAbility : public abilityImpl{
  int player;
  int slot;
  public:
  void activate(Board *board) override;
  void changeTarget(int player, int slot);
  DestroyAbility(std::string description, int cost, int player, int slot);
}

#endif

#ifndef DISABLEABILITY_H
#define DISABLEABILITY_H

#include "abilityImpl.h"

class DisableAbility : public abilityImpl{
  int player;
  int slot;
  public:
  void activate(Board) override;
  void changeTarget(int player, int slot);
  DisableAbility(std::string description, int cost, int player, int slot);
}

#endif

#ifndef ACTCOSTABILITY_H
#define ACTCOSTABILITY_H

#include "abilityImpl.h"

class ActCostAbility : public abilityImpl{
  int player;
  int slot;
  int costMod;
  public:
  void activate(Board *board) override;
  void changeCost(int newCost);
  void changeTarget(int player, int slot);
  ActCostAbility(std::string description, int cost, int player, int slot, 
                 int costMod);
}

#endif

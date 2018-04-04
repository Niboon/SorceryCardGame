#ifndef CHANGEABILITY_H
#define CHANGEABILITY_H

#include "abilityImpl.h"

class ChangeAbility : public abilityImpl {
  int amount;
  int player;
  int slot;
  bool allMinions;
  public:
  void activate(Board *board) override;
  void newTarget(int player, int slot; bool allMinions);
  void newAmount(int amount);
  ChangeAbility(std::string description, int cost, int amount, int player, 
                int slot, bool allMinions);
};

#endif

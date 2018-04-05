#ifndef TRIGGER_ABILITY_H
#define TRIGGER_ABILITY_H

#include "ability.h"
#include "triggerObserver.h"
#include "phase.h"
#include <string>
#include <memory>
#include <functional>

class Board;

class TriggerAbility : public Ability {
public:
  TriggerAbility(std::string description,
                 std::function<void(Board *b, int tP, int tS)> funcPtr,
                 bool onMyTurn,
                 bool onOppTurn,
                 Phase phase);
  void applyEffect(Board* board, int player, int slot) override;
  void applyEffect(Board* board) override;
  int getCost() const override;
  std::string getDescription() const override;
  std::unique_ptr<TriggerObserver> &getObserver();
  ~TriggerAbility() = default;
private:
  std::function<void (Board *b, int tP, int tS)> effect;
  int cost;
  std::string description;
  std::unique_ptr<TriggerObserver> observer;
};

#endif

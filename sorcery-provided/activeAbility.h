#ifndef ACTIVE_ABILITY_H
#define ACTIVE_ABILITY_H

#include "ability.h"
#include <string>
#include <memory>
#include <functional>

class Board;

class ActiveAbility : public Ability {
public:
  ActiveAbility(std::string description, std::function<void (Board *b, int tP, int tS)> funcPtr);
  void applyEffect(Board* board, int player, int slot) override;
  void applyEffect(Board* board) override;
  int getCost() const override;
  std::string getDescription() const override;
  ~ActiveAbility() = default;
private:
  std::function<void (Board *b, int tP, int tS)> effect;
  int cost;
  std::string description;
};

#endif

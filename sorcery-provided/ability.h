#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include <memory>

class Board;

class Ability {
  struct AbilityType{
    virtual activate(Board *board) = 0;
    virtual ~AbilityType() = default;
  }
  std::unique_ptr<AbilityType> type;
  std::string description;
  int cost;
  public:
  std::string getDesc();
  int getCost();
  void applyEffect(Board* board);
  Ability(std::string abilityText);
  virtual ~Ability() = default;
};

#endif

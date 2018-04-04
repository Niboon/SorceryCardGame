#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include <memory>

class AbiImpl;
class Board;

class Ability {
  std::unique_ptr<AbiImpl> pImpl;
  public:
  void applyEffect(Board* board);
  Ability(std::string abilityText);
  virtual ~Ability() = default;
};

#endif

#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include <memory>

class AbiImpl;
class Board;

class Ability {
  protected:
  std::unique_ptr<AbiImpl> pImpl;
  public:
  void applyEffect(Board board);
  Ability(int cost, std::string desc);
  virtual ~Ability();
};

#endif

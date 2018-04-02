#ifndef ABILITY_H
#define ABILITY_H

#include <string>

class Board;

class Ability {
  std::string description;
  int cost;
  Board *board;
  public:
  virtual void applyEffect() = 0;
  Ability(int cost, std::string desc);
  virtual ~Ability();
}

#endif

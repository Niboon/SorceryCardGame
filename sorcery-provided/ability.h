#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include <memory>
#include <functional>

class Board;

class Ability {
public:
  virtual void applyEffect(Board* board, int player, int slot) = 0;
  virtual void applyEffect(Board* board) = 0;
  virtual std::string getDescription() const = 0;
  virtual int getCost() const = 0;
  virtual ~Ability() = default;
};

#endif

#ifndef ABILITYIMPL_H
#define ABILITYIMPL_H

#include <string>

class AbilityImpl{
  std::string description;
  int cost;
public:
  std::string getDesc();
  int getCost();
  virtual activate(Board board) = 0;
  AbilityImpl(std::string description, int cost);
  virtual ~AbiImpl() = default;
};

#endif

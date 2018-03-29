#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>
#include "ascii_graphics.h"

class Card {
public:
  virtual std::string getName() const = 0;

  virtual int getCost() const = 0;

  virtual std::vector<std::string> getDraw() = 0;

  virtual ~Card() = default;
};

#endif //CARD_H

#ifndef HAND_H
#define HAND_H

#include <string>
#include <vector>
#include <memory>
#include "card.h"

class Hand {
  std::vector<std::unique_ptr<Card>> cards;
public:
  Hand();

  std::unique_ptr<Card> takeCard(int which);

  void addCard(std::unique_ptr<Card> newCard);

  std::string getDraw();

  Hand(Hand &other);

  ~Hand();
};

#endif

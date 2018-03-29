#ifndef HAND_H
#define HAND_H

#include <utility>

class Card;

class Hand {
  std::vector<std::unique_ptr<Card>> hand;
public:
  Card takeCard(int which);

  void addCard(Card newCard);

  string getDraw();

  Hand();

  Hand(Hand &other);

  ~Hand();
}

#endif

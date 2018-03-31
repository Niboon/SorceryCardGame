#ifndef HAND_H
#define HAND_H

static const int HAND_CARD_LIMIT = 5;

#include <string>
#include <vector>
#include <memory>
#include "card.h"

class Hand {
  std::vector<std::unique_ptr<Card>> cards;
public:
  std::unique_ptr<Card> takeCard(int which);

  bool addCard(std::unique_ptr<Card> newCard);

  int getSize() const;

  card_template_t getDraw() const;
};

#endif

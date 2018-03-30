#ifndef DECK_H
#define DECK_H

#include <string>
#include <memory>
#include <vector>
#include "card.h"

class Deck {
private:
  std::vector<std::unique_ptr<Card>> cards;
public:
  Deck(std::vector<std::string> cardNames);

  void shuffle();

  std::unique_ptr<Card> popCard();

  void pushCard(std::unique_ptr<Card> newCard);

  Deck(Deck &other);

  ~Deck();
};

#endif

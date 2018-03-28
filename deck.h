#ifndef DECK_H
#define DECK_H
#include <utility>

class Card;

class Deck{
  std::vector<std::unique_ptr<Card>> deck;
  public:
  void shuffle();
  Card popCard();
  void pushCard(Card newCard);
  Deck(Card *cards);
  Deck(Deck &other);
  ~Deck();
}

#endif

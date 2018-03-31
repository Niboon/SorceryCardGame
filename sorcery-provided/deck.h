#ifndef DECK_H
#define DECK_H

#include <string>
#include <map>
#include <memory>
#include <vector>
#include "card.h"

class Deck {
private:
public:
  Deck(std::vector<std::string> cardNames, std::vector<std::string> loader);

  std::vector<std::unique_ptr<Card>> cards;

  void shuffleDeck(int nonce=1);

  std::unique_ptr<Card> popCard();

  void pushCard(std::unique_ptr<Card> newCard);

  Deck(Deck &other);

  ~Deck();
};

void insertPair(std::map<std::string, std::string> &params, const std::string &key, std::stringstream &ss);

void loadCard(const std::string &name, std::map<std::string, std::string> &cardParams,
              std::vector<std::unique_ptr<Card>> &deckCards);

#endif

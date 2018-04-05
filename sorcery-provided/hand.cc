#include "hand.h"

using namespace std;

unique_ptr<Card> Hand::takeCard(int which) {
  unique_ptr<Card> ret{move(cards.at(which-1))};
  cards.erase(cards.begin() + (which-1));
  return move(ret);
}

int Hand::getCardCost(int which) {
  return (cards.at(which-1)->getCost());
}

bool Hand::addCard(unique_ptr<Card> newCard) {
  if (getSize() < HAND_CARD_LIMIT && newCard) {
    cards.emplace_back(move(newCard));
    return true;
  }
  return false;
}

card_template_t Hand::getDraw() const {
  card_template_t ret(CARD_TEMPLATE_EMPTY.size());
  for (const auto &card : cards) {
    int i = 0;
    for (const auto &line : card->getDraw()) {
      ret[i] += line;
      i++;
    }
  }
  return ret;
}

int Hand::getSize() const {
  if (!cards.empty()) {
    return static_cast<int>(cards.size());
  } else {
    return 0;
  }
}

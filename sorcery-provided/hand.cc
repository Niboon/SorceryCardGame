#include "hand.h"

using namespace std;

Hand::Hand() = default;

unique_ptr<Card> Hand::takeCard(int which) {
  unique_ptr<Card> ret{move(cards.at(which))};
  cards.erase(cards.begin() + which);
  return move(ret);
}

void Hand::addCard(unique_ptr<Card> newCard) {
  cards.emplace_back(move(newCard));
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

Hand::Hand(Hand &other) {

}

Hand::~Hand() {

}

#include "player.h"

using namespace std;


Player::Player(const std::string &name, std::vector<std::string> cardNames,
               std::vector<std::string> loader, bool testing) :
        name{name},
        deck{move(make_unique<Deck>(cardNames, loader, testing))},
        hand{move(make_unique<Hand>())},
        testing(testing)
{
  magic = STARTING_MAGIC;
  life = STARTING_LIFE;
  for (int i=0; i<STARTING_HAND_LIMIT; ++i) {
    hand->addCard(move(deck->popCard()));
  }
}

// returns whether draw was successful
bool Player::drawCard() {
  if (deck->getSize()>0) {
    return hand->addCard(move(deck->popCard()));
  }
  return false;
}

void Player::changeLife(int amount) {
  life += amount;
}

bool Player::changeMagic(int amount) {
  if (magic + amount < 0 && !testing) {
    return false;
  } else if (magic + amount < 0 && testing) {
    magic = 0;
    return true;
  } else {
    magic += amount;
    return true;
  }
}

std::unique_ptr<Card> Player::getCard(int num) {
  return move(hand->takeCard(num));
}

bool Player::hasEnoughMagic(int num) {
  bool b = magic > hand->getCardCost(num);
  if (testing) b=true;
  return b;
}

card_template_t Player::showHand() const{
  return hand->getDraw();
}

void Player::insertDeckBottom(std::unique_ptr<Card> &&card) {
  deck->insertToBottom(move(card));
}

card_template_t Player::getDraw(int playerNumber) const{
  return display_player_card(playerNumber, name, life, magic);
}

Player::~Player() {

}

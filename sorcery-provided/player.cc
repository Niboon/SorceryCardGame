#include "player.h"

using namespace std;


Player::Player(const string &name, vector<string> cardNames) :
        name{name},
        deck{make_unique<Deck>(cardNames)}
{
  magic = STARTING_MAGIC;
  life = STARTING_LIFE;
  for (int i=0; i<STARTING_HAND_LIMIT; ++i) {
    hand->addCard(move(deck->popCard()));
  }
}

Player::Player(Player &other) {

}

void Player::drawCard() {

}

std::unique_ptr<Card> Player::getCard(int num) {
  return hand->takeCard(num);
}

card_template_t Player::showHand() {
  return card_template_t();
}

card_template_t Player::getDraw() {
  return card_template_t();
}

Player::~Player() {

}

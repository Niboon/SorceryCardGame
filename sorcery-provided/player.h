#ifndef PLAYER_H
#define PLAYER_H

static const int STARTING_MAGIC = 3;
static const int STARTING_LIFE = 20;
static const int STARTING_HAND_LIMIT = 4;

#include <string>
#include <memory>
#include "deck.h"
#include "hand.h"

class Player {
private:
  std::string name;
  int magic;
  int life;
  std::unique_ptr<Deck> deck;
  std::unique_ptr<Hand> hand;
public:
  Player(const std::string &name, std::vector<std::string> cardNames);

  Player(Player &other);

  void drawCard();

  std::unique_ptr<Card> getCard(int num);

  card_template_t showHand();

  card_template_t getDraw();

  ~Player();
};

#endif

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <memory>
#include "card.h"

class Deck;

class Hand;

class Player {
private:
  std::string name;
  int magic;
  int life;
  std::unique_ptr<Deck> deck;
  std::unique_ptr<Hand> hand;
public:
  Player(const std::string &name, int magic, int life,
         std::vector<std::string> cardNames);

  Player(Player &other);

  void drawCard();

  Card getCard(int num);

  card_template_t showHand();

  card_template_t getDraw();

  ~Player();
};

#endif

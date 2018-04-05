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
  bool testing;
  std::unique_ptr<Deck> deck;
  std::unique_ptr<Hand> hand;
public:
  Player(const std::string &name, std::vector<std::string> cardNames, std::vector<std::string> loader, bool testing);

  bool drawCard();

  void changeLife(int amount);

  std::unique_ptr<Card> getCard(int num);

  bool hasEnoughMagic(int num);

  card_template_t showHand() const;

  card_template_t getDraw(int playerNumber) const;

  ~Player();

  void insertDeckBottom(std::unique_ptr<Card> &&card);

  bool changeMagic(int amount);
};

#endif

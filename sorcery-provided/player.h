#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <utility>

class Card;

class Deck;

class Hand;

class Player {
  string name;
  int magic;
  int life;
  std::unique_ptr<Deck> deck;
  std::unique_ptr<Hand> hand;
public:
  void drawCard();

  Card getCard(int num);

  string showHand();

  string getDraw();

  Player(string &name, int magic, int life, std::vector<Card> deck);

  Player(Player &other);

  ~Player();
}

#endif

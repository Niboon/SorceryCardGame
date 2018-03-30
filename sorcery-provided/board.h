#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <string>
#include "subject.h"

class Player;

class Card;

class Ritual : public Card;

class Minion : public Card;

class Enchantment : public Card;

class TriggerObserver;

class Board : public Subject {
  std::unique_ptr<Player> p1, p2;
  int activePlayer;
  std::unique_ptr<std::vector<Card>> graveyard1, graveyard2;
  std::unique_ptr<Ritual> ritual1, rirtual2;
  std::vector<std::shared_ptr<Minion>> minions1, minions2;
  std::vector<TriggerObserver *> observersPlayer1, observersPlayer2;
public:
  std::string getDraw();

  int whoseTurn();

  int opponent();

  std::shared_ptr<Minion> minion(int player, int slot);

  void drawCard(int player);

  void play(int player, int card);

  void play(int player, int card, int targPlayer, int target);

  void use(int player, int slot);

  void use(int player, int slot, int targPlayer, int target);

  void injure(int player, int slot, int damage);

  void destroy(int player, int slot);

  void enchant(int player, int slot, Enchantment enchant);

  void summon(int player, Minion token);

  int endTurn();

  std::string showHand(int player);

  std::string getDraw();

  Board(std::string p1, std::string p2, Card *cards, int initMagic, int initLife);

  ~Board();
}

#endif

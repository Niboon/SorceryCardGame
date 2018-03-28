#ifndef BOARD_H
#define BOARD_H
#include <utility>
#include <string>
#include "subject.h"

class Player;
class Card;
class Ritual: public Card;
class Minion: public Card;
class Enchantment: public Card;
class TriggerObserver;

class Board: public Subject{
  std::unique_ptr<Player> p1;
  std::unique_ptr<Player> p2;
  int activePlayer;
  std::unique_ptr<std::vector<Card>> graveyard1;
  std::unique_ptr<std::vector<Card>> graveyard2;
  std::unique_ptr<Ritual> ritual1;
  std::unique_ptr<Ritual> ritual2;
  std::unique_ptr<std::vector<Minion>> minions1;
  std::unique_ptr<std::vector<Minion>> minions2;
  std::vector<TriggerObserver *> observersPlayer1;
  std::vector<TriggerObserver *> observersPlayer2;
  public:
  string getDraw();
  int whoseTurn();
  void drawCard(int player);
  void play(int player, int card);
  void play(int player, int card, int targPlayer, int target);
  void use(int player, int slot);
  void use(int player, int slot, int targPlayer, int target);
  void injure(int player, int slot);
  void destroy(int player, int slot);
  void enchant(int player, int slot, Enchantment enchant);
  void summon(int player, Minion token);
  int endTurn();
  string showHand(int player);
  string getDraw();
}

#endif

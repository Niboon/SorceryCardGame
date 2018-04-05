#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <string>
#include "subject.h"
#include "minion.h"
#include "enchantment.h"
#include "statsEnchantmentCard.h"
#include "abilityEnchantmentCard.h"
#include "player.h"
#include "creature.h"
//#include "ritual.h"

class Board : public Subject {
private:
  std::unique_ptr<Player> p1, p2;
  int activePlayer;
  std::vector<std::unique_ptr<Minion>> graveyard1, graveyard2;
//  std::unique_ptr<Ritual> ritual1, ritual2;
  std::vector<std::unique_ptr<Minion>> minions1, minions2;
  std::vector<bool> minionsAct1, minionsAct2;
  std::vector<TriggerObserver *> observersPlayer1, observersPlayer2;

  std::vector<std::unique_ptr<Minion>> &refPlayerMinions(int player);

  std::vector<bool> &refMinionActs(int player);

  Player *getPlayer(int player);
public:
  Board(std::vector<std::string> deck1, std::vector<std::string> deck2, std::string name1, std::string name2,
          std::vector<std::string> loader, bool testing);

  void attach(int player, TriggerObserver *observer) override;

  void detach(int player, TriggerObserver *observer) override;

  void notify(bool isYourTurn, Phase phase) override;

  int whoseTurn();

  int opponent();

  std::unique_ptr<Minion> &getMinion(int player, int slot);

  int getMinionCount(int player);

  void drawCard(int player);

  void play(int player, int slot);

  void play(int player, int slot, int targetPlayer, int targetSlot);

  void use(int player, int slot);

  void use(int player, int slot, int targetPlayer, int targetSlot);

  void changeLife(int player, int amount);

  void destroy(int player, int slot);

  void enchant(int player, int slot, std::unique_ptr<EnchantmentCard> enchantmentCard);

  void summon(int player, std::unique_ptr<Minion> creature);

  void endTurn();

  void startTurn();

  void discard(int player, int card);

  card_template_t showHand(int player);

  card_template_t getDraw();

  card_template_t inspect(int player, int slot);

  ~Board();

  bool hasMinion(int player, int slot);

  bool hasAction(int player, int slot);

  void setAction(int player, int slot, bool val);

  void returnToDeck(int player, int slot);

  void destroyEnchantment(int player, int slot);

  void changeDef(int amount);

  void changeDef(int player, int amount);

  void changeDef(int player, int amount, int slot);

  void changeAtk(int amount);

  void changeAtk(int player, int amount);

  void changeAtk(int player, int amount, int slot);

  void changeMagic(int player, int amount);

  void specialSummon(int player, std::string name, int count);

  void changeCharge(int player, int amount);

  void resurrect(int player);

  bool tryUseCost(int player, int cost);
};

std::unique_ptr <Enchantment> doEnchant(std::unique_ptr<Minion> minion,
                                   std::unique_ptr<EnchantmentCard> enchantmentCard);

void insertPlayerRow(unsigned long long int height, card_template_t &ret, const card_template_t &ritualDraw1,
                     const card_template_t &graveyardDraw1, const card_template_t &playerDraw1);

void insertMinionRow(unsigned long long int height, card_template_t &ret,
                     std::vector<std::unique_ptr<Minion>> &minions);

#endif

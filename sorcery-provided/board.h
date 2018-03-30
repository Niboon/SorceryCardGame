#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <string>
#include "subject.h"
#include "ritual.h"
#include "minion.h"
#include "enchantment.h"
#include "StatsEnchantmentCard.h"
#include "AbilityEnchantmentCard.h"
#include "triggerObserver.h"

class Player;

class Board : public Subject {
private:
  std::unique_ptr<Player> p1, p2;
  int activePlayer;
  std::vector<std::unique_ptr<Card>> graveyard1, graveyard2;
  std::unique_ptr<Ritual> ritual1, ritual2;
  std::vector<std::shared_ptr<Minion>> minions1, minions2;
  std::vector<TriggerObserver *> observersPlayer1, observersPlayer2;
public:
  Board(std::vector<std::string> deck1, std::vector<std::string> deck2,
        std::string name1, std::string name2);

  void attach(int player, TriggerObserver *observer) override;

  void detach(int player, TriggerObserver *observer) override;

  void notify(bool isYourTurn, Phase phase) override;

  int whoseTurn();

  int opponent();

  std::shared_ptr<Minion> &getMinion(int player, int slot);

  void drawCard(int player);

  void play(int player, int slot);

  void play(int player, int slot, int targetPlayer, int targetSlot);

  void use(int player, int slot);

  void use(int player, int slot, int targetPlayer, int targetSlot);

  void injure(int player, int damage);
  void injure(int player, int damage, int slot);

  void destroy(int player, int slot);

  void enchant(int player, int slot, std::unique_ptr<EnchantmentCard> enchantmentCard);

  void summon(int player, std::shared_ptr<Minion> minion);

  void endTurn();

  card_template_t showHand(int player);

  std::string getDraw();

  Board(std::string p1, std::string p2, Card *cards, int initMagic, int initLife);

  ~Board();
};

std::shared_ptr<Enchantment> doEnchant(std::shared_ptr<Minion> minion,
                                       std::unique_ptr<EnchantmentCard> enchantmentCard);


#endif

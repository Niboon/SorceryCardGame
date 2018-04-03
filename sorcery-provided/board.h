#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <string>
#include "subject.h"
#include "ritual.h"
#include "minion.h"
#include "enchantment.h"
#include "statsEnchantmentCard.h"
#include "abilityEnchantmentCard.h"
#include "player.h"
#include "creature.h"

class Board : public Subject {
private:
  std::unique_ptr<Player> p1, p2;
  int activePlayer;
  std::vector<std::unique_ptr<Minion>> graveyard1, graveyard2;
  std::unique_ptr<Ritual> ritual1, ritual2;
  std::vector<std::unique_ptr<Minion>> minions1, minions2;
  std::vector<TriggerObserver *> observersPlayer1, observersPlayer2;

  std::vector<std::unique_ptr<Minion>> &refPlayerMinions(int player);

  Player *getPlayer(int player);
public:
  Board(std::vector<std::string> deck1, std::vector<std::string> deck2,
        std::string name1, std::string name2, std::vector<std::string> loader);

  void attach(int player, TriggerObserver *observer) override;

  void detach(int player, TriggerObserver *observer) override;

  void notify(bool isYourTurn, Phase phase) override;

  int whoseTurn();

  int opponent();

  std::unique_ptr<Minion> &getMinion(int player, int slot);

  void drawCard(int player);

  void play(int player, int slot);

  void play(int player, int slot, int targetPlayer, int targetSlot);

  void use(int player, int slot);

  void use(int player, int slot, int targetPlayer, int targetSlot);

  void changeLife(int player, int amount);
  void changeDef(int player, int amount, int slot);

  void destroy(int player, int slot);

  void enchant(int player, int slot, std::unique_ptr<EnchantmentCard> enchantmentCard);

  void summon(int player, std::unique_ptr<Minion> creature);

  void endTurn();

  card_template_t showHand(int player);

  card_template_t getDraw();

  card_template_t inspect(int player, int slot);

  ~Board();

  bool hasMinion(int player, int slot);
};

std::unique_ptr <Enchantment> doEnchant(std::unique_ptr<Minion> minion,
                                   std::unique_ptr<EnchantmentCard> enchantmentCard);


#endif

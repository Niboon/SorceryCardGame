#include "board.h"
#include "statsEnchantment.h"
#include "abilityEnchantment.h"

using namespace std;


Board::Board(vector<string> deck1, vector<string> deck2, string name1, string name2) {
//    init player1
//
//    init player2
//
}

void Board::attach(int player, TriggerObserver *observer) {

}

void Board::detach(int player, TriggerObserver *observer) {

}

void Board::notify(bool isYourTurn, Phase phase) {

}

int Board::whoseTurn() {
  return 0;
}

int Board::opponent() {
  return 0;
}

void Board::drawCard(int player) {

}

void Board::play(int player, int slot) {

}

void Board::play(int player, int slot, int targetPlayer, int targetSlot) {

}

void Board::use(int player, int slot) {

}

void Board::use(int player, int slot, int targetPlayer, int targetSlot) {

}

void Board::injure(int player, int damage) {

}

void Board::injure(int player, int damage, int slot) {

}

void Board::destroy(int player, int slot) {

}


void Board::enchant(int player, int minion, std::unique_ptr<EnchantmentCard> enchantmentCard) {
  if (player == 1){
    minions1.at(minion) = doEnchant(move(minions1.at(minion)), move(enchantmentCard));
  }
  else if (player == 2){
    minions2.at(minion) = doEnchant(move(minions1.at(minion)), move(enchantmentCard));
  }
}

std::shared_ptr<Minion> &Board::getMinion(int player, int slot) {
  if (player == 1) {
    return minions1.at(slot);
  } else {
    return minions2.at(slot);
  }
}

void Board::summon(int player, std::shared_ptr<Minion> minion) {

}

void Board::endTurn() {

}

card_template_t Board::showHand(int player) {
  return card_template_t();
}

card_template_t Board::getDraw() {
  return CENTRE_GRAPHIC;
}

Board::~Board() {

}

shared_ptr<Enchantment> doEnchant(shared_ptr<Minion> minion,
                                  unique_ptr<EnchantmentCard> enchantmentCard) {
  if (enchantmentCard->getAbility()) {
    return make_shared<AbilityEnchantment>(move(minion), move(enchantmentCard));
  } else {
    return make_shared<StatsEnchantment>(move(minion), move(enchantmentCard));
  }
}

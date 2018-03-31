#include "board.h"
#include "statsEnchantment.h"
#include "abilityEnchantment.h"

using namespace std;


Board::Board(vector<string> deck1, vector<string> deck2, string name1, string name2) {
Board::Board(vector<string> deck1, vector<string> deck2, string name1, string name2,
             vector<string> loader) {
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
  if(player == 1) p1->drawCard();
  else p2->drawCard();

}

void Board::play(int player, int slot) {
  shared_ptr<Card> c;
  if(player == 1) c = p1->playCard(card);
  else c = p2->playCard(card);
  if (dynamic_pointer_cast<Minion>(c)){
    summon(player, c);
  }
  else if (dynamic_pointer_cast<Ritual>(c)){
    destroy(player, 0);
    if (player == 1) ritual1 = c;
    else ritual2 = c;
  }
  else {
    c->ability()->applyEffect();
    if (player == 1) graveyard1->emplace_back(c);
    else graveyard2->emplace_back(c);
  }
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


void Board::enchant(int player, int minion, unique_ptr<EnchantmentCard> enchantmentCard) {
  if (player == 1){
    minions1.at(minion) = doEnchant(move(minions1.at(minion)), move(enchantmentCard));
  }
  else if (player == 2){
    minions2.at(minion) = doEnchant(move(minions1.at(minion)), move(enchantmentCard));
  }
}

shared_ptr<Minion> &Board::getMinion(int player, int slot) {
  if (player == 1) {
    return minions1.at(slot);
  } else {
    return minions2.at(slot);
  }
}

void Board::summon(int player, shared_ptr<Minion> minion) {

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

#include "board.h"
#include "statsEnchantment.h"
#include "abilityEnchantment.h"

using namespace std;

Board::Board(vector<string> deck1,
             vector<string> deck2,
             string name1,
             string name2,
             vector<string> loader) :
        p1{make_unique<Player>(name1, deck1, loader)},
        p2{make_unique<Player>(name2, deck2, loader)},
        activePlayer{1}
{}

void Board::attach(int player, TriggerObserver *observer) {

}

void Board::detach(int player, TriggerObserver *observer) {

}

void Board::notify(bool isYourTurn, Phase phase) {

}

int Board::whoseTurn() {
  return activePlayer;
}

int Board::opponent() {
  return (activePlayer == 1) ? 2 : 1;
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
  if (player == 1) minions1.at(slot)->ability()->applyEffect();
  else minions2.at(slot)->ability()->applyEffect();
}

void Board::use(int player, int slot, int targetPlayer, int targetSlot) {

}

void Board::injure(int player, int damage) {
  if (player == 1) p1->damage(damage);
  else p2->damage(damage);
}

void Board::injure(int player, int damage, int slot) {
  if (player == 1) minions1.at(slot)->damage(damage);
  else minions2.at(slot)->damage(damage);
}

void Board::destroy(int player, int slot) {
  if (player == 1){
    if (slot) minions1.erase(begin()+slot-1);
    else ritual1 = nullptr;
  }
  else{
    if (slot) minions2.erase(being()+slot-1);
    else ritual2 = nullptr;
  }
}


void Board::enchant(int player, int minion, unique_ptr<EnchantmentCard> enchantmentCard) {
  if (player == 1){
    minions1.at(minion-1) = doEnchant(move(minions1.at(minion-1)), move(enchantmentCard));
  }
  else if (player == 2){
    minions2.at(minion-1) = doEnchant(move(minions1.at(minion-1)), move(enchantmentCard));
  }
}

unique_ptr<Minion> Board::getMinion(int player, int slot) {
  if (player == 1) {
    unique_ptr<Minion> ptr = move(minions1.at(slot - 1));
    return move(ptr);
  } else {
    unique_ptr<Minion> ptr = move(minions2.at(slot - 1));
    return move(ptr);
  }
}

void Board::summon(int player, unique_ptr<Minion> creature) {
  if (player == 1) {
    minions1.emplace_back(move(creature));
  } else {
    minions2.emplace_back(move(creature));
  }
}

void Board::endTurn() {

}

card_template_t Board::showHand(int player) {
  if (player == 1) return p1->showHand();
  else return p2->showHand();
}

card_template_t Board::getDraw() {
  return CENTRE_GRAPHIC;
}

Board::~Board() {

}

unique_ptr<Enchantment> doEnchant(unique_ptr<Minion> minion,
                                  unique_ptr<EnchantmentCard> enchantmentCard) {
  if (enchantmentCard->getAbility()) {
    return move(make_unique<AbilityEnchantment>(move(minion), move(enchantmentCard)));
  } else {
    return move(make_unique<StatsEnchantment>(move(minion), move(enchantmentCard)));
  }
}

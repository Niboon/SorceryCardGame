#include "board.h"
#include "statsEnchantment.h"
#include "abilityEnchantment.h"
#include "creature.h"
#include "spell.h"

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
  Player *p = getPlayer(player);
  unique_ptr<Card> card = p->getCard(slot);
  if (auto creaturePtr = dynamic_cast<Creature*>(card.get())){
    card.release();
    summon(player, move(unique_ptr<Minion>{creaturePtr}));
  } else if (auto ritualPtr = dynamic_cast<Ritual*>(card.get())){
    card.release();
    unique_ptr<Ritual> newRitual{ritualPtr};
    (player == 1) ? ritual1.swap(newRitual) : ritual2.swap(newRitual);
  } else if (auto spellPtr = dynamic_cast<Spell*>(card.get())){
    card.release();
    unique_ptr<Spell> spell = move(unique_ptr<Spell>(spellPtr));
//    spell->getAbility()->applyEffect(this);
  }
}

void Board::play(int player, int slot, int targetPlayer, int targetSlot) {
  Player *p = getPlayer(player);
  unique_ptr<Card> card = p->getCard(slot);
  if (auto statsEnchantmentCardPtr = dynamic_cast<StatsEnchantmentCard*>(card.get())){
    card.release();
    enchant(targetPlayer,
            targetSlot,
            move(unique_ptr<EnchantmentCard>{statsEnchantmentCardPtr})
    );
  } else if (auto abilityEnchantmentCardPtr = dynamic_cast<AbilityEnchantmentCard*>(card.get())){
    card.release();
    enchant(targetPlayer,
            targetSlot,
            move(unique_ptr<EnchantmentCard>{abilityEnchantmentCardPtr})
    );
  } else if (auto spellPtr = dynamic_cast<Spell*>(card.get())){
    card.release();
    unique_ptr<Spell> spell = move(unique_ptr<Spell>(spellPtr));
//    spell->getAbility()->applyEffect(targetPlayer, targetSlot, this);
  }
}

void Board::use(int player, int slot) {
  vector<unique_ptr<Minion>> &minions = refPlayerMinions(player);
  unique_ptr<Minion> &minion = minions.at(slot-1);
//  minion->getAbility()->applyEffect(this);
}

void Board::use(int player, int slot, int targetPlayer, int targetSlot) {
  vector<unique_ptr<Minion>> &minions = refPlayerMinions(player);
  unique_ptr<Minion> &minion = minions.at(slot-1);
//  minion->getAbility()->applyEffect(targetPlayer, targetSlot, this);
}

void Board::injure(int player, int amount) {
  Player *p = getPlayer(player);
  p->changeLife(-amount);
}

void Board::injure(int player, int amount, int slot) {
  vector<unique_ptr<Minion>> &minions = refPlayerMinions(player);
  minions.at(slot-1)->changeDef(-amount);
  if (minions.at(slot-1)->getDef() <= 0) destroy(player, slot);
}

void Board::destroy(int player, int slot) {
  vector<unique_ptr<Minion>> &minions = refPlayerMinions(player);
  unique_ptr<Minion> minion = move(minions.at(slot - 1));
//  minion->destroy();
  minions.erase(minions.begin() + slot);
  graveyard1.emplace_back(minion.get());
}


void Board::enchant(int player, int minion, unique_ptr<EnchantmentCard> enchantmentCard) {
  vector<unique_ptr<Minion>> &minions = refPlayerMinions(player);
  minions.at(minion - 1) = doEnchant(move(minions.at(minion - 1)), move(enchantmentCard));
}

const unique_ptr<Minion> &Board::getMinion(int player, int slot) {
  return refPlayerMinions(player).at(slot - 1);
}

void Board::summon(int player, unique_ptr<Minion> creature) {
  vector<unique_ptr<Minion>> &minions = refPlayerMinions(player);
  minions.emplace_back(move(creature));
}

void Board::endTurn() {
  activePlayer = opponent();
}

card_template_t Board::showHand(int player) {
  return getPlayer(player)->showHand();
}

card_template_t Board::getDraw() {
  return CENTRE_GRAPHIC;
}

card_template_t Board::inspect(int player, int slot) {
    return getMinion(player, slot)->getDraw();
}

Board::~Board() {

}

Player *Board::getPlayer(int player) {
  return (player == 1) ? p1.get() : p2.get();
}

vector<unique_ptr<Minion>> &Board::refPlayerMinions(int player) {
  vector<unique_ptr<Minion>> &minions = (player == 1) ? minions1 : minions2;
  return minions;
}

unique_ptr<Enchantment> doEnchant(unique_ptr<Minion> minion,
                                  unique_ptr<EnchantmentCard> enchantmentCard) {
  if (enchantmentCard->getAbility()) {
    return move(make_unique<AbilityEnchantment>(move(minion), 
                                                move(enchantmentCard)));
  } else {
    return move(make_unique<StatsEnchantment>(move(minion), 
                                              move(enchantmentCard)));
  }
}

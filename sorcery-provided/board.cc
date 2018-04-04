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
//  } else if (auto ritualPtr = dynamic_cast<Ritual*>(card.get())){
//    card.release();
//    unique_ptr<Ritual> newRitual{ritualPtr};
//    (player == 1) ? ritual1.swap(newRitual) : ritual2.swap(newRitual);
//  } else if (auto spellPtr = dynamic_cast<Spell*>(card.get())){
//    card.release();
//    unique_ptr<Spell> spell = move(unique_ptr<Spell>(spellPtr));
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
//  } else if (auto abilityEnchantmentCardPtr = dynamic_cast<AbilityEnchantmentCard*>(card.get())){
//    card.release();
//    enchant(targetPlayer,
//            targetSlot,
//            move(unique_ptr<EnchantmentCard>{abilityEnchantmentCardPtr})
//    );
//  } else if (auto spellPtr = dynamic_cast<Spell*>(card.get())){
//    card.release();
//    unique_ptr<Spell> spell = move(unique_ptr<Spell>(spellPtr));
//    spell->getAbility()->applyEffect(targetPlayer, targetSlot, this);
  }
}

void Board::use(int player, int slot) {
  if (!hasMinion(player, slot))
    return;
  unique_ptr<Minion> &minion = getMinion(player, slot);
//  minion->getAbility()->applyEffect(this);
}

void Board::use(int player, int slot, int targetPlayer, int targetSlot) {
  if (!hasMinion(player, slot))
    return;
  unique_ptr<Minion> &minion = getMinion(player, slot);
//  minion->getAbility()->applyEffect(targetPlayer, targetSlot, this);
}

void Board::destroy(int player, int slot) {
  vector<unique_ptr<Minion>> &minions = refPlayerMinions(player);
  unique_ptr<Minion> minion = move(minions.at(slot - 1));
  unique_ptr<Minion> deadMinion = minion->destroy();
  minions.erase(minions.begin() + (slot - 1));
  vector<unique_ptr<Minion>> &graveyard = (player == 1) ? graveyard1 : graveyard2;
  graveyard.emplace_back(move(deadMinion));
}

void Board::enchant(int player, int minion, unique_ptr<EnchantmentCard> enchantmentCard) {
  vector<unique_ptr<Minion>> &minions = refPlayerMinions(player);
  minions.at(minion - 1) = doEnchant(move(minions.at(minion - 1)), move(enchantmentCard));
}

unique_ptr<Minion> &Board::getMinion(int player, int slot) {
  return refPlayerMinions(player).at(slot - 1);
}

int Board::getMinionCount(int player) {
  return static_cast<int>(refPlayerMinions(player).size());
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
  const card_template_t &centre = CENTRE_GRAPHIC;
  unsigned long long int height = CARD_TEMPLATE_BORDER.size();
  string topBorder (165, EXTERNAL_BORDER_CHAR_LEFT_RIGHT.at(0));
  topBorder = EXTERNAL_BORDER_CHAR_TOP_LEFT + topBorder + EXTERNAL_BORDER_CHAR_TOP_RIGHT;
  string bottomBorder (165, EXTERNAL_BORDER_CHAR_LEFT_RIGHT.at(0));
  bottomBorder = EXTERNAL_BORDER_CHAR_BOTTOM_LEFT + bottomBorder + EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT;
  card_template_t ret;
  ret.emplace_back(topBorder);
  const card_template_t ritualDraw1 =
          (ritual1.get())
          ? ritual1->getDraw()
          : CARD_TEMPLATE_BORDER;
  const card_template_t graveyardDraw1 =
          (!graveyard1.empty())
          ? graveyard1.back()->getDraw()
          : CARD_TEMPLATE_BORDER;
  const card_template_t ritualDraw2 =
          (ritual2.get())
          ? ritual2->getDraw()
          : CARD_TEMPLATE_BORDER;
  const card_template_t graveyardDraw2 =
          (!graveyard2.empty())
          ? graveyard2.back()->getDraw()
          : CARD_TEMPLATE_BORDER;
  const card_template_t playerDraw1 = p1->getDraw(1);
  const card_template_t playerDraw2 = p2->getDraw(2);
  insertPlayerRow(height, ret, ritualDraw1, graveyardDraw1, playerDraw1);
  insertMinionRow(height, ret, minions1);
  for (const auto &line : centre) {
    ret.emplace_back(line);
  }
  insertMinionRow(height, ret, minions2);
  insertPlayerRow(height, ret, ritualDraw2, graveyardDraw2, playerDraw2);
  ret.emplace_back(bottomBorder);
  return ret;
}

card_template_t Board::inspect(int player, int slot) {
  if (hasMinion(player, slot))
    return (getMinion(player, slot))->getInspect();
  else
    return {"Error: There's no minion in that slot!"};
}

bool Board::hasMinion(int player, int slot) { return refPlayerMinions(player).size() >= slot; }


Player *Board::getPlayer(int player) {
  return (player == 1) ? p1.get() : p2.get();
}

vector<unique_ptr<Minion>> &Board::refPlayerMinions(int player) {
  vector<unique_ptr<Minion>> &minions = (player == 1) ? minions1 : minions2;
  return minions;
}

void Board::changeLife(int player, int amount) {
  Player *p = getPlayer(player);
  p->changeLife(-amount);
}
void Board::changeAtk(int player, int amount, int slot) {
  unique_ptr<Minion> &minion = getMinion(player, slot);
  minion->changeAtk(amount);
}

// changeAtk all of given player's minions
void Board::changeAtk(int player, int amount) {
  for (int slot=1; slot<=getMinionCount(player); ++slot) {
    changeAtk(player, amount, slot);
  }
}

// changeAtk all minions
void Board::changeAtk(int amount) {
  changeAtk(1, amount);
  changeAtk(2, amount);
}

void Board::changeDef(int player, int amount, int slot) {
  unique_ptr<Minion> &minion = getMinion(player, slot);
  minion->changeDef(amount);
  if (minion->getDef() <= 0) destroy(player, slot);
}

// changeDef all minions of given player
void Board::changeDef(int player, int amount) {
  for (int slot=1; slot<=getMinionCount(player); ++slot) {
    changeDef(player, amount, slot);
  }
}

// changeDef all minions
void Board::changeDef(int amount) {
  changeDef(1, amount);
  changeDef(2, amount);
}

void Board::returnToDeck(int player, int slot) {
  vector<unique_ptr<Minion>> &minions = refPlayerMinions(player);
  unique_ptr<Minion> minion = move(minions.at(slot - 1));
  unique_ptr<Minion> returnedMinion = minion->destroy();
  minions.erase(minions.begin() + (slot - 1));
  Player *p = getPlayer(player);
  p->insertDeckBottom(move(returnedMinion));
}

void Board::resurrect(int player) {
  vector<unique_ptr<Minion>> &graveyard = (player == 1) ? graveyard1 : graveyard2;
  unique_ptr<Minion> rMinion = move(graveyard.back());
  graveyard.pop_back();
  vector<unique_ptr<Minion>> &minions = refPlayerMinions(player);
  minions.emplace_back(rMinion);
}

void Board::destroyEnchantment(int player, int slot) {
}

void Board::changeMagic(int player, int amount) {
  Player *p = getPlayer(player);
  p->changeMagic(amount);
}

void Board::specialSummon(int i, std::string name, int count) {

}

void Board::changeCharge(int player, int amount) {
  Ritual *ritual = (player == 1) ? ritual1.get() : ritual2.get();
  ritual->changeCharge(amount);
}

Board::~Board() {

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

void insertPlayerRow(unsigned long long int height, card_template_t &ret,
                     const card_template_t &ritualDraw1, const card_template_t &graveyardDraw1,
                     const card_template_t &playerDraw1) {
  for (int i=0; i < height; ++i) {
    string newLine = EXTERNAL_BORDER_CHAR_UP_DOWN;
    newLine += ritualDraw1.at(i);
    newLine += CARD_TEMPLATE_EMPTY.at(i);
    newLine += playerDraw1.at(i);
    newLine += CARD_TEMPLATE_EMPTY.at(i);
    newLine += graveyardDraw1.at(i);
    newLine += EXTERNAL_BORDER_CHAR_UP_DOWN;
    ret.emplace_back(newLine);
  }
}

void insertMinionRow(unsigned long long int height, card_template_t &ret,
                     vector<unique_ptr<Minion>> &minions) {
  for (int i=0; i < height; ++i) {
    string newLine = EXTERNAL_BORDER_CHAR_UP_DOWN;
    for (int j=0; j < 5; ++j) {
      if (j < minions.size()) {
        const card_template_t &minion = minions[j]->getDraw();
        newLine += minion.at(i);
      } else {
        newLine += CARD_TEMPLATE_BORDER.at(i);
      }
    }
    newLine += EXTERNAL_BORDER_CHAR_UP_DOWN;
    ret.emplace_back(newLine);
  }
}

#include "statsEnchantment.h"

#include <utility>
#include "ascii_graphics.h"

using namespace std;

StatsEnchantment::StatsEnchantment(unique_ptr<Minion> minion, unique_ptr<EnchantmentCard> enchantmentCard) :
        Enchantment{move(minion)}, enchantmentCard{move(enchantmentCard)}
{}

card_template_t StatsEnchantment::getDraw() const {
  return display_minion_no_ability(
          Enchantment::getName(),
          Enchantment::getCost(),
          getAtk(),
          getDef());
}

card_template_t StatsEnchantment::getInspect() const {
  int height = CARD_TEMPLATE_EMPTY.size();
  int width = CARD_TEMPLATE_EMPTY.front().size();
  const card_template_t &previous = Enchantment::getInspect();
  int pSize = previous.size();
  int newSize = (pSize == height) ? pSize * 2 : pSize;
  card_template_t ret(newSize);
  int i = 0;
  for (auto it=ret.begin(); it<(ret.begin() + pSize); ++it) {
    *it += previous.at(i);
    ++i;
  }
  card_template_t enchantment = display_enchantment_attack_defence(
          enchantmentCard->getName(),
          enchantmentCard->getCost(),
          "",
          to_string(enchantmentCard->getAtk()),
          to_string(enchantmentCard->getDef()));
  if (pSize == height) {
    int j = 0;
    for (auto it=ret.begin()+height; it<ret.end(); ++it) {
      *it += enchantment.at(j);
      ++j;
    }
  } else if (ret.back().size() < 5*width) {
    int j = 0;
    for (auto it=(ret.begin() + pSize-height); it < ret.end(); ++it) {
      *it += enchantment.at(j);
      ++j;
    }
  } else {
    for (auto line : enchantment) {
      ret.emplace_back(line);
    }
  }
  return ret;
}

int StatsEnchantment::getAtk() const {
  return Enchantment::getAtk() + enchantmentCard->getAtk();
}

int StatsEnchantment::getDef() const {
  return Enchantment::getDef() + enchantmentCard->getDef();
}

int StatsEnchantment::getAbility() const {
  return 0;
}

StatsEnchantment::~StatsEnchantment() = default;



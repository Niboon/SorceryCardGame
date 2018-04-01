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



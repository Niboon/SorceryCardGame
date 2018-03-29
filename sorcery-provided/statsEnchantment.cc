#include "statsEnchantment.h"

#include <utility>
#include "ascii_graphics.h"

using namespace std;

StatsEnchantment::StatsEnchantment(std::shared_ptr<Minion> minion, unique_ptr<EnchantmentCard> enchantmentCard) :
        Enchantment{move(minion)}, enchantmentCard{move(enchantmentCard)}
{}

card_template_t StatsEnchantment::getDraw() const {
  return display_enchantment_attack_defence(
          Enchantment::getName(),
          Enchantment::getCost(),
          "",
          to_string(getAtk()),
          to_string(getDef()));
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



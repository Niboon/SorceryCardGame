#include "statsEnchantment.h"

#include <utility>
#include "ascii_graphics.h"

using namespace std;

StatsEnchantment::StatsEnchantment(std::shared_ptr<Minion> minion, int atk, int def) :
        Enchantment{std::move(minion)}, atk{atk}, def{def} {}

card_template_t StatsEnchantment::getDraw() const {
  return display_enchantment_attack_defence(
          Enchantment::getName(),
          Enchantment::getCost(),
          "",
          to_string(getAtk()),
          to_string(getDef()));
}

int StatsEnchantment::getAtk() const {
  return Enchantment::getAtk() + atk;
}

int StatsEnchantment::getDef() const {
  return Enchantment::getDef() + def;
}

int StatsEnchantment::getAbility() const {
  return 0;
}

StatsEnchantment::~StatsEnchantment() = default;


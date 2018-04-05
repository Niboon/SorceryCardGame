#include "statsEnchantmentCard.h"

using namespace std;

StatsEnchantmentCard::StatsEnchantmentCard(const string &name, int cost, int atk, int def):
        name{name},
        cost{cost},
        atk{atk},
        def{def}
{}

string StatsEnchantmentCard::getName() const {
  return name;
}

int StatsEnchantmentCard::getCost() const {
  return cost;
}

int StatsEnchantmentCard::getAtk() const {
  return atk;
}

int StatsEnchantmentCard::getDef() const {
  return def;
}

Ability * StatsEnchantmentCard::getAbility() const {
  return nullptr;
}

card_template_t StatsEnchantmentCard::getDraw() const {
  return display_enchantment_attack_defence(
          getName(),
          getCost(),
          "",
          to_string(getAtk()),
          to_string(getDef()));
}


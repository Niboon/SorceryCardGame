#include "abilityEnchantmentCard.h"

using namespace std;

AbilityEnchantmentCard::AbilityEnchantmentCard(const string &name, int cost, int ability):
        name{name},
        cost{cost},
        ability{ability}
{}

string AbilityEnchantmentCard::getName() const {
  return name;
}

string AbilityEnchantmentCard::getType() const {
  return "AbilityEnchantmentCard";
}

int AbilityEnchantmentCard::getCost() const {
  return cost;
}

int AbilityEnchantmentCard::getAtk() const {
  return 0;
}

int AbilityEnchantmentCard::getDef() const {
  return 0;
}

int AbilityEnchantmentCard::getAbility() const {
  return 0;
}

card_template_t AbilityEnchantmentCard::getDraw() const {
  return display_enchantment_attack_defence(
          getName(),
          getCost(),
          "getAbility()",
          "",
          "");
}

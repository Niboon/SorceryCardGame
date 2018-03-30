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

int AbilityEnchantmentCard::getCost() const {
  return cost;
}

int AbilityEnchantmentCard::getAtk() const {
  return nullptr;
}

int AbilityEnchantmentCard::getDef() const {
  return nullptr;
}

int AbilityEnchantmentCard::getAbility() const {
  return ability;
}

card_template_t AbilityEnchantmentCard::getDraw() {
  return display_enchantment_attack_defence(
          getName(),
          getCost(),
          getAbility(),
          "",
          "");
}

#include "abilityEnchantmentCard.h"

using namespace std;

AbilityEnchantmentCard::AbilityEnchantmentCard(const string &name, int cost, unique_ptr<Ability> ability):
        name{name},
        cost{cost},
        ability{move(ability)}
{}

string AbilityEnchantmentCard::getName() const {
  return name;
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

Ability * AbilityEnchantmentCard::getAbility() const {
  return ability.get();
}

card_template_t AbilityEnchantmentCard::getDraw() const {
  return display_enchantment_attack_defence(
          getName(),
          getCost(),
          "getAbility()",
          "",
          "");
}

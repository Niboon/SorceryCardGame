#include "abilityEnchantment.h"

using namespace std;

AbilityEnchantment::AbilityEnchantment(unique_ptr<Minion> minion,
                                       unique_ptr<EnchantmentCard> enchantmentCard) :
        Enchantment{move(minion)},enchantmentCard{move(enchantmentCard)}
{}

card_template_t AbilityEnchantment::getDraw() const {
  return card_template_t();
}

card_template_t AbilityEnchantment::getInspect() const {
  return card_template_t();
}

int AbilityEnchantment::getAtk() const {
  return Enchantment::getAtk();
}

int AbilityEnchantment::getDef() const {
  return Enchantment::getDef();
}

int AbilityEnchantment::getAbility() const {
  return enchantmentCard->getAbility();
}

unique_ptr<Minion> AbilityEnchantment::destroy() {
  return Enchantment::destroy();
}

unique_ptr<Minion> AbilityEnchantment::removeTop() {
  return Enchantment::removeTop();
}

AbilityEnchantment::~AbilityEnchantment() = default;

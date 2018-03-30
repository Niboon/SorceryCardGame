#include "abilityEnchantment.h"

AbilityEnchantment::AbilityEnchantment(std::shared_ptr<Minion> minion,
                                       std::unique_ptr<EnchantmentCard> enchantmentCard) :
        Enchantment{move(minion)},enchantmentCard{move(enchantmentCard)}
{}

card_template_t AbilityEnchantment::getDraw() const {
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

AbilityEnchantment::~AbilityEnchantment() = default;

#ifndef ABILITYENCHANTMENT_H
#define ABILITYENCHANTMENT_H

#include "enchantment.h"
#include "enchantmentCard.h"


class AbilityEnchantment : public Enchantment {
public:
  AbilityEnchantment(std::unique_ptr<Minion> minion, std::unique_ptr<EnchantmentCard> enchantmentCard);

  card_template_t getDraw() const override;

  int getAtk() const override;

  int getDef() const override;

  Ability * getAbility() const override;

  std::unique_ptr<Minion> destroy() override;

  std::unique_ptr<Minion> removeTop() override;

  ~AbilityEnchantment() override;

private:
  int atk;
  int def;
  std::unique_ptr<EnchantmentCard> enchantmentCard;

  card_template_t getInspect() const;
};


#endif //ABILITYENCHANTMENT_H

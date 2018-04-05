#ifndef ABILITYENCHANTMENTCARD_H
#define ABILITYENCHANTMENTCARD_H

#include "enchantmentCard.h"


class AbilityEnchantmentCard : public EnchantmentCard {
public:
  AbilityEnchantmentCard(const std::string &name, int cost, std::unique_ptr<Ability> ability);

  std::string getName() const override;

  int getCost() const override;

  int getAtk() const override;

  int getDef() const override;

  Ability * getAbility() const override;

  card_template_t getDraw() const override;

  ~AbilityEnchantmentCard() override = default;

private:
  std::string name;
  int cost;
  std::unique_ptr<Ability> ability;
};


#endif //ABILITYENCHANTMENTCARD_H

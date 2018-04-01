#ifndef STATSENCHANTMENTCARD_H
#define STATSENCHANTMENTCARD_H

#include "enchantmentCard.h"


class StatsEnchantmentCard : public EnchantmentCard {
public:
  StatsEnchantmentCard(const std::string &name, int cost, int atk, int def);

  std::string getName() const override;

  int getCost() const override;

  std::string getType() const override;

  int getAtk() const override;

  int getDef() const override;

  int getAbility() const override;

  card_template_t getDraw() const override;

  ~StatsEnchantmentCard() override = default;

private:
  std::string name;
  int cost;
  int atk;
  int def;
};


#endif //STATSENCHANTMENTCARD_H

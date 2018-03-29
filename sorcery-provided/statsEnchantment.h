#ifndef STATSENCHANTMENT_H
#define STATSENCHANTMENT_H

#include <vector>
#include "enchantment.h"


class StatsEnchantment : public Enchantment {
public:
  StatsEnchantment(std::shared_ptr<Minion> minion, int atk, int def);

  card_template_t getDraw() override;

  int getAtk() const override;

  int getDef() const override;

  int getAbility() const override;

  ~StatsEnchantment() override;

private:
  int atk;
  int def;
};

#endif //STATSENCHANTMENT_H

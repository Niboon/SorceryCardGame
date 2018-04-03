#ifndef STATSENCHANTEMENT_H
#define STATSENCHANTEMENT_H

#include <vector>
#include "enchantment.h"
#include "statsEnchantmentCard.h"

class StatsEnchantment : public Enchantment {
public:
  StatsEnchantment(std::unique_ptr<Minion> minion, std::unique_ptr<EnchantmentCard> enchantmentCard);

  card_template_t getDraw() const override;

  card_template_t getInspect() const override;

  int getAtk() const override;

  int getDef() const override;

  int getAbility() const override;

  ~StatsEnchantment() override;

private:
  int atk;
  int def;
  std::unique_ptr<EnchantmentCard> enchantmentCard;
};

#endif //STATSENCHANTEMENT_H

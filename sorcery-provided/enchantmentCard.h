#ifndef ENCHANTMENTCARD_H
#define ENCHANTMENTCARD_H

#include <string>
#include <memory>
#include "card.h"
#include "ability.h"

class EnchantmentCard : public Card {
public:
  virtual std::string getName() const = 0;

  virtual int getCost() const = 0;

  virtual card_template_t getDraw() const = 0;

  virtual int getAtk() const = 0;

  virtual int getDef() const = 0;

  virtual Ability * getAbility() const = 0;

  ~EnchantmentCard() override = default;
};


#endif //ENCHANTMENTCARD_H

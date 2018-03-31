#ifndef SPELL_H
#define SPELL_H

#include <string>
#include "card.h"
#include "phase.h"

class Spell : public Card {
public:
  Spell(std::string name, int cost, std::string abilityDescription, int abilityCost, int ability);

  std::string getName() const override;

  int getCost() const override;

  card_template_t getDraw() const override;

  ~Spell() override;

private:
//    Ability ability;
};

#endif //SPELL_H

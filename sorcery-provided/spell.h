#ifndef SPELL_H
#define SPELL_H

#include <string>
#include "card.h"
#include "phase.h"
#include "ability.h"

class Spell : public Card {
public:
  Spell(std::string name, int cost, std::unique_ptr<Ability> ability);

  std::string getName() const override;

  int getCost() const override;

  std::string getDescription() const;

  std::unique_ptr<Ability> &getAbility();

  card_template_t getDraw() const override;

  ~Spell() override;

private:
  std::string name;
  int cost;
  std::unique_ptr<Ability> ability;
};

#endif //SPELL_H

#ifndef RITUAL_H
#define RITUAL_H

#include <string>
#include "card.h"
#include "phase.h"

class Ritual : public Card {
public:
  Ritual(std::string name, int cost, std::string abilityDescription, int abilityCost, Phase phase, bool onMyTurn);

  card_template_t getDraw() const override;

  ~Ritual() override;

private:
//    TriggeredAbility ability;
};

#endif //RITUAL_H

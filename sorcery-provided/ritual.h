#ifndef RITUAL_H
#define RITUAL_H

#include <string>
#include "card.h"
#include "phase.h"

class Ritual : public Card {
public:
  Ritual(std::string name, int cost, int triggerAbility, int charges);

  std::string getName() const override;

  int getCost() const override;

  card_template_t getDraw() const override;

  ~Ritual() override;

private:
//    TriggeredAbility ability;
};

#endif //RITUAL_H

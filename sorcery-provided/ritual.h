#ifndef RITUAL_H
#define RITUAL_H

#include <string>
#include "card.h"
#include "phase.h"
#include "ability.h"
#include "triggerAbility.h"

class Ritual : public Card {
public:
  Ritual(std::string name, int cost, std::unique_ptr<TriggerAbility> triggerAbility, int charge);

  std::string getName() const override;

  int getCost() const override;

  void changeCharge(int amount);

  card_template_t getDraw() const override;

  std::unique_ptr<TriggerAbility> &getTriggerAbility();

  ~Ritual() override;

private:
  std::string name;
  int cost;
  std::unique_ptr<TriggerAbility> triggerAbility;
  int charge;
};

#endif //RITUAL_H

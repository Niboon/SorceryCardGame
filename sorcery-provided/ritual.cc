#include "ritual.h"

#include <utility>

using namespace std;

Ritual::Ritual(std::string name, int cost, std::unique_ptr<TriggerAbility> triggerAbility, int charge) :
        name{std::move(name)},
        cost{cost},
        triggerAbility{move(triggerAbility)},
        charge{charge}
{}

std::string Ritual::getName() const {
  return name;
}

int Ritual::getCost() const {
  return cost;
}

void Ritual::changeCharge(int amount) {
  charge += amount;
}

card_template_t Ritual::getDraw() const {
  return display_ritual(name,cost,triggerAbility->getCost(),triggerAbility->getDescription(),charge);
}

unique_ptr<TriggerAbility> &Ritual::getTriggerAbility() {
  return triggerAbility;
}

Ritual::~Ritual() = default;

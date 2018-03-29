#include "creature.h"

using namespace std;

Creature::Creature(const std::string &name, int cost, int atk, int def, int ability) :
        name{name},
        cost{cost},
        atk{atk},
        def{def},
        ability{ability} {}

std::string Creature::getName() const {
  return name;
}

int Creature::getCost() const {
  return cost;
}

int Creature::getAtk() const {
  return atk;
}

int Creature::getDef() const {
  return def;
}

int Creature::getAbility() const {
  return ability;
}

card_template_t Creature::getDraw() {
  return display_enchantment_attack_defence(
          getName(),
          getCost(),
          "",
          to_string(getAtk()),
          to_string(getDef()));
}

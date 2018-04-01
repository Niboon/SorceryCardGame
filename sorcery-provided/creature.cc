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

void Creature::changeAtk(int amount) {
  atk += amount;
}

void Creature::changeDef(int amount) {
  def += amount;
}

int Creature::getAbility() const {
  return ability;
}

card_template_t Creature::getDraw() const {
  return display_minion_no_ability(
          getName(),
          getCost(),
          getAtk(),
          getDef());
}

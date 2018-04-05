#include "creature.h"
#include "ability.h"

using namespace std;

Creature::Creature(const std::string &name, int cost, int atk, int def, unique_ptr<Ability> ability) :
        orgName{name},
        orgCost{cost},
        orgAtk{atk},
        orgDef{def},
        orgAbility{move(ability)},
        name{name},
        cost{cost},
        atk{atk},
        def{def},
        ability{orgAbility.get()}
{}

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

Ability * Creature::getAbility() const {
  return ability;
}

std::string Creature::getOrgName() const {
  return orgName;
}

int Creature::getOrgCost() const {
  return orgCost;
}

int Creature::getOrgAtk() const {
  return orgAtk;
}

int Creature::getOrgDef() const {
  return orgDef;
}

Ability & Creature::getOrgAbility() const {
  return *orgAbility;
}

void Creature::changeAtk(int amount) {
  atk += amount;
}

void Creature::changeDef(int amount) {
  def += amount;
}

std::unique_ptr<Minion> Creature::destroy() {
  return move(make_unique<Creature>(orgName, orgCost,orgAtk,orgDef, move(orgAbility)));
}

std::unique_ptr<Minion> Creature::removeTop() {
  return move(make_unique<Creature>(orgName, orgCost,orgAtk,orgDef, move(orgAbility)));
}

card_template_t Creature::getDraw() const {
  return display_minion_no_ability(
          getName(),
          getCost(),
          getAtk(),
          getDef());
}

card_template_t Creature::getInspect() const {
  return display_minion_no_ability(
          getOrgName(),
          getOrgCost(),
          getOrgAtk(),
          getOrgDef());
}

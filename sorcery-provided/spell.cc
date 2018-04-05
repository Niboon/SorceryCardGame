#include "spell.h"

using namespace std;

Spell::Spell(string name, int cost, unique_ptr<Ability> ability) :
        name{name},
        cost{cost},
        ability{move(ability)}
{}

std::string Spell::getName() const {
  return name;
}

int Spell::getCost() const {
  return cost;
}

std::string Spell::getDescription() const {
  return ability->getDescription();
}

unique_ptr<Ability> &Spell::getAbility(){
  return ability;
}

card_template_t Spell::getDraw() const {
  return display_spell(name, cost, getDescription());
}

Spell::~Spell() {

}

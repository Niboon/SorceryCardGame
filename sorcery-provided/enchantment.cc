#include "enchantment.h"

using namespace std;

Enchantment::Enchantment(unique_ptr<Minion> minion) :
        minion{move(minion)},
        orgName{this->minion->getOrgName()},
        orgCost{this->minion->getOrgCost()},
        orgAtk{this->minion->getOrgAtk()},
        orgDef{this->minion->getOrgDef()},
        orgAbility{this->minion->getOrgAbility()}
{}

string Enchantment::getName() const {
  return minion->getName();
}

int Enchantment::getCost() const {
  return minion->getCost();
}

int Enchantment::getAtk() const {
  return minion->getAtk();
}

int Enchantment::getDef() const {
  return minion->getDef();
}

Ability * Enchantment::getAbility() const {
  return minion->getAbility();
}

string Enchantment::getOrgName() const {
  return orgName;
}

int Enchantment::getOrgCost() const {
  return orgCost;
}

int Enchantment::getOrgAtk() const {
  return orgAtk;
}

int Enchantment::getOrgDef() const {
  return orgDef;
}

Ability &Enchantment::getOrgAbility() const {
  return orgAbility;
}

void Enchantment::changeAtk(int amount) {
  minion->changeAtk(amount);
}

void Enchantment::changeDef(int amount) {
  minion->changeDef(amount);
}

unique_ptr<Minion> Enchantment::destroy() {
  minion->changeAtk(orgAtk);
  minion->changeDef(orgDef);
  return move(minion->destroy());
}

unique_ptr<Minion> Enchantment::removeTop() {
  minion->changeAtk(orgAtk);
  minion->changeDef(orgDef);
  return move(minion);
}

card_template_t Enchantment::getDraw() const {
  return minion->getDraw();
}

card_template_t Enchantment::getInspect() const {
  return minion->getInspect();
}

Enchantment::~Enchantment() = default;

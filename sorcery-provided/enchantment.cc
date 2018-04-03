#include "enchantment.h"

Enchantment::Enchantment(std::unique_ptr<Minion> minion) :
        minion{std::move(minion)},
        orgName{this->minion->getOrgName()},
        orgCost{this->minion->getOrgCost()},
        orgAtk{this->minion->getOrgAtk()},
        orgDef{this->minion->getOrgDef()},
        orgAbility{this->minion->getOrgAbility()}
{}

std::string Enchantment::getName() const {
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

int Enchantment::getAbility() const {
  return minion->getAbility();
}

std::string Enchantment::getOrgName() const {
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

int Enchantment::getOrgAbility() const {
  return orgAbility;
}

void Enchantment::changeAtk(int amount) {
  minion->changeAtk(amount);
}

void Enchantment::changeDef(int amount) {
  minion->changeDef(amount);
}

card_template_t Enchantment::getDraw() const {
  return minion->getDraw();
}

card_template_t Enchantment::getInspect() const {
  return minion->getInspect();
}

Enchantment::~Enchantment() = default;

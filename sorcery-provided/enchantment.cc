#include "enchantment.h"

Enchantment::Enchantment(std::unique_ptr<Minion> minion) : minion{std::move(minion)} {}

card_template_t Enchantment::getDraw() const {
  return minion->getDraw();
}

int Enchantment::getAtk() const {
  return minion->getAtk();
}

void Enchantment::changeAtk(int amount) {
  minion->changeAtk(amount);
}

void Enchantment::changeDef(int amount) {
  minion->changeDef(amount);
}

int Enchantment::getDef() const {
  return minion->getDef();
}

int Enchantment::getAbility() const {
  return minion->getAbility();
}

std::string Enchantment::getName() const {
  return minion->getName();
}

int Enchantment::getCost() const {
  return minion->getCost();
}

Enchantment::~Enchantment() = default;

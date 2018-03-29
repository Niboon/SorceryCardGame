#include "enchantment.h"

Enchantment::Enchantment(std::shared_ptr<Minion> minion) : minion{std::move(minion)} {}

card_template_t Enchantment::getDraw() {
  return minion->getDraw();
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

std::string Enchantment::getName() const {
  return minion->getName();
}

int Enchantment::getCost() const {
  return minion->getCost();
}

Enchantment::~Enchantment() = default;

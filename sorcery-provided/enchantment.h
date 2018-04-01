#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include <string>
#include <memory>
#include "minion.h"
#include "phase.h"

class Enchantment : public Minion {
public:
  explicit Enchantment(std::unique_ptr<Minion> minion);

  virtual card_template_t getDraw() const;

  virtual std::string getName() const;

  virtual int getCost() const;

  virtual int getAtk() const;

  virtual int getDef() const;

  virtual void changeAtk(int amount);

  virtual void changeDef(int amount);

  virtual int getAbility() const;

  ~Enchantment() override;

private:
  std::unique_ptr<Minion> minion;
};


#endif //ENCHANTMENT_H

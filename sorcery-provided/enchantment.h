#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include <string>
#include <memory>
#include "minion.h"
#include "phase.h"

class Enchantment : public Minion {
public:
  explicit Enchantment(std::unique_ptr<Minion> minion);

  virtual std::string getName() const;

  virtual int getCost() const;

  virtual int getAtk() const;

  virtual int getDef() const;

  virtual Ability * getAbility() const;

  virtual std::string getOrgName() const;

  virtual int getOrgCost() const;

  virtual int getOrgAtk() const;

  virtual int getOrgDef() const;

  virtual Ability & getOrgAbility() const;

  virtual void changeAtk(int amount);

  virtual void changeDef(int amount);

  virtual std::unique_ptr<Minion> destroy();

  virtual std::unique_ptr<Minion> removeTop();

  virtual card_template_t getDraw() const;

  virtual card_template_t getInspect() const;

  ~Enchantment() override;

private:
  std::unique_ptr<Minion> minion;

  const std::string orgName;
  const int orgCost;
  const int orgAtk;
  const int orgDef;
  Ability &orgAbility;
};


#endif //ENCHANTMENT_H

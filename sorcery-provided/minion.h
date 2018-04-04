#ifndef MINION_H
#define MINION_H

#include <string>
#include "card.h"
#include "phase.h"

class Minion : public Card {
public:
  virtual std::string getName() const = 0;

  virtual int getCost() const = 0;

  virtual int getAtk() const = 0;

  virtual int getDef() const = 0;

  virtual int getAbility() const = 0;

  virtual std::string getOrgName() const = 0;

  virtual int getOrgCost() const = 0;

  virtual int getOrgAtk() const = 0;

  virtual int getOrgDef() const = 0;

  virtual int getOrgAbility() const = 0;

  virtual void changeAtk(int amount) = 0;

  virtual void changeDef(int amount) = 0;

  virtual std::unique_ptr<Minion> destroy() = 0;

  virtual card_template_t getDraw() const = 0;

  virtual card_template_t getInspect() const = 0;

  ~Minion() override = default;
};


#endif //MINION_H

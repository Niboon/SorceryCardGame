#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <memory>
#include "minion.h"

class Creature : public Minion {
public:
  Creature(const std::string &name, int cost, int atk, int def, int ability);

  std::string getName() const override;

  int getCost() const override;

  int getAtk() const override;

  int getDef() const override;

  int getAbility() const override;

  virtual std::string getOrgName() const;

  virtual int getOrgCost() const override;

  virtual int getOrgAtk() const override;

  virtual int getOrgDef() const override;

  virtual int getOrgAbility() const override;

  void changeAtk(int amount) override;

  void changeDef(int amount) override;

  std::unique_ptr<Minion> destroy() override;

  std::unique_ptr<Minion> removeTop() override;

  card_template_t getDraw() const override;

  card_template_t getInspect() const override;

  ~Creature() override = default;

private:
  std::string name;
  int cost;
  int atk;
  int def;
  int ability;

  const std::string orgName;
  const int orgCost;
  const int orgAtk;
  const int orgDef;
  const int orgAbility;
};


#endif //CREATURE_H

#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <memory>
#include "minion.h"
#include "ability.h"

class Creature : public Minion {
public:
  Creature(const std::string &name, int cost, int atk, int def, std::unique_ptr<Ability> ability);

  std::string getName() const override;

  int getCost() const override;

  int getAtk() const override;

  int getDef() const override;

  Ability * getAbility() const override;

  virtual std::string getOrgName() const;

  virtual int getOrgCost() const override;

  virtual int getOrgAtk() const override;

  virtual int getOrgDef() const override;

  virtual Ability & getOrgAbility() const override;

  void changeAtk(int amount) override;

  void changeDef(int amount) override;

  std::unique_ptr<Minion> destroy() override;

  std::unique_ptr<Minion> removeTop() override;

  card_template_t getDraw() const override;

  card_template_t getInspect() const override;

  ~Creature() override = default;

private:
  const std::string orgName;
  const int orgCost;
  const int orgAtk;
  const int orgDef;
  std::unique_ptr<Ability> orgAbility;

  std::string name;
  int cost;
  int atk;
  int def;
  Ability *ability;
};


#endif //CREATURE_H

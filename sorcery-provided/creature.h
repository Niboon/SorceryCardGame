#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include "minion.h"

class Creature : public Minion {
public:
  Creature(const std::string &name, int cost, int atk, int def, int ability);

  std::string getName() const override;

  int getCost() const override;

  int getAtk() const override;

  int getDef() const override;

  void changeAtk(int amount) override;

  void changeDef(int amount) override;

  int getAbility() const override;

  card_template_t getDraw() const override;

  ~Creature() override = default;

private:
  std::string name;
  int cost;
  int atk;
  int def;
  int ability;
};


#endif //CREATURE_H

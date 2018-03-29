#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include <string>
#include <memory>
#include "minion.h"
#include "phase.h"

class Enchantment : public Minion {
public:
    explicit Enchantment(std::shared_ptr<Minion> minion);

    virtual card_template_t getDraw();

    virtual std::string getName() const;

    virtual int getCost() const;

    virtual int getAtk() const;

    virtual int getDef() const;

    virtual int getAbility() const;

    ~Enchantment() override;

private:
    std::shared_ptr<Minion> minion;
};


#endif //ENCHANTMENT_H

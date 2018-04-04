#include "ability.h"
#include <string>
#include <stringstream>

using namespace std;

Ability::Ability(string abilityText){ }

void Ability::applyEffect(Board* board){
  type->activate(board);
}

string Ability::getDesc(){
    return description;
}

int Ability::getCost(){
    return cost;
}

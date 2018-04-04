#include "ability.h"
#include <string>
#include <stringstream>

using namespace std;

Ability(string abilityText){ }

void applyEffect(Board* board){
  pImpl->activate(board);
}

#include "activeAbility.h"

using namespace std;

ActiveAbility::ActiveAbility(string description, function<void (Board*, int, int)> funcPtr) :
        description {move(description)},
        effect {move(funcPtr)}
{}

void ActiveAbility::applyEffect(Board* board, int player, int slot){
  effect(board, player, slot);
}

void ActiveAbility::applyEffect(Board* board){
  applyEffect(board, 0, 0);
}

string ActiveAbility::getDescription() const {
  return description;
}

int ActiveAbility::getCost() const{
    return cost;
}

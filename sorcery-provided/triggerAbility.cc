#include "triggerAbility.h"
#include "phaseObserver.h"

using namespace std;

TriggerAbility::TriggerAbility(std::string description, std::function<void(Board *b, int tP, int tS)> funcPtr, bool onMyTurn,
                               bool onOppTurn, Phase phase) :
        description {move(description)},
        effect {move(funcPtr)},
        observer {make_unique<PhaseObserver>(onMyTurn, onOppTurn, phase)}
{
  observer->setAbility(this);
}

void TriggerAbility::applyEffect(Board* board, int player, int slot){
  effect(board, player, slot);
}

void TriggerAbility::applyEffect(Board* board){
  applyEffect(board, 0, 0);
}

string TriggerAbility::getDescription() const {
  return description;
}

int TriggerAbility::getCost() const{
    return cost;
}

unique_ptr<TriggerObserver> &TriggerAbility::getObserver() {
  return observer;
}

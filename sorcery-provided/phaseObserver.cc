#include "phaseObserver.h"

PhaseObserver::PhaseObserver(bool onMyTurn, bool onOppTurn, Phase onPhase) :
        onMyTurn {onMyTurn},
        onOppTurn {onOppTurn},
        onPhase {onPhase}
{}

void PhaseObserver::trigger(bool isMyTurn, Phase phase, Board *board) {
  if (phase == onPhase && (isMyTurn == onMyTurn || isMyTurn != onOppTurn)) {
    ability->applyEffect(board);
  }
}

void PhaseObserver::trigger(bool isMyTurn, Phase phase, Board *board, int targetSlot) {
  if (phase == onPhase && (isMyTurn == onMyTurn || isMyTurn != onOppTurn)) {
    int player = (onMyTurn) ? board->whoseTurn() : board->opponent();
    ability->applyEffect(board, player, targetSlot);
  }
}

void PhaseObserver::setAbility(Ability *ability) {
  this->ability = ability;
}

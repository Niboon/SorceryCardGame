#ifndef TRIGGEROBSERVER_H
#define TRIGGEROBSERVER_H

#include <memory>
#include "phase.h"
#include "board.h"

class TriggerObserver {
public:
  virtual void trigger(bool isMyTurn, Phase phase, Board *board) = 0;
  virtual void trigger(bool isMyTurn, Phase phase, Board *board,
                       int targetSlot) = 0;
  virtual void setAbility(Ability *ability) = 0;
  virtual ~TriggerObserver() = default;
};


#endif //TRIGGEROBSERVER_H

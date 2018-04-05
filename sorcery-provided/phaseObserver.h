#ifndef PHASEOBSERVER_H
#define PHASEOBSERVER_H

#include "triggerObserver.h"
#include "ability.h"

class PhaseObserver : public TriggerObserver {
public:
  PhaseObserver(bool onMyTurn, bool onOppTurn, Phase onPhase);
  void trigger(bool isMyTurn, Phase phase, Board *board) override;
  void trigger(bool isMyTurn, Phase phase, Board *board,
               int targetSlot) override;
  void setAbility(Ability *ability) override;
  ~PhaseObserver() override = default;

private:
  bool onMyTurn;
  bool onOppTurn;
  Phase onPhase;
  Ability *ability;
};

#endif //PHASEOBSERVER_H

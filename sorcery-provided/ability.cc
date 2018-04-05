//#include "ability.h"

using namespace std;

Ability::Ability(string description, function<void (Board*, int, int)> funcPtr) :
        description {move(description)},
        effect {move(funcPtr)}
{}

void Ability::applyEffect(Board* board, int player, int slot){
  effect(board, player, slot);
}

void Ability::applyEffect(Board* board){
  applyEffect(board, 0, 0);
}

string Ability::getDescription() const {
  return description;
}

int Ability::getCost(){
    return cost;
}

//
//class Ability::Effect{
//public:
//  explicit Effect(function<void (Board* b, int tP, int tS)>);
//  void activate(Board *board);
//  void activate(Board *board, int player, int slot);
//  ~Effect() = default;
//private:
//  function<void (Board* b, int tP, int tS)> funcPtr;
//};
//
//Ability::Effect::Effect(function<void (Board* b, int tP, int tS)> funcPtr) :
//        funcPtr{move(funcPtr)}
//{}
//
//void Ability::Effect::activate(Board *board, int player, int slot) {
//  funcPtr(board ,player ,slot);
//}
//
//void Ability::Effect::activate(Board *board) {
//  funcPtr(board ,0 ,0);
//}
//
//void Ability::applyEffect(Board* board, int player, int slot){
//  effect->activate(board);
//}
//
//void Ability::applyEffect(Board* board){
//  applyEffect(board, 0, 0);
//}

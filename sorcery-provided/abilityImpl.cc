#include "abilityImpl.h"
#include <string>

using namespace std;

string AbilityImpl::getDesc(){
  return description;
}

int AbilityImpl::getCost(){
  return cost;
}

AbilityImpl::AbilityImpl(string description, int cost)
  : description{description}, cost{cost} { }


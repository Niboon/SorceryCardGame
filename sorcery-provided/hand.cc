#include "hand.h"

using namespace std;

Hand::Hand() {

}

unique_ptr<Card> Hand::takeCard(int which) {
  return unique_ptr<Card>();
}

void Hand::addCard(unique_ptr<Card> newCard) {

}

string Hand::getDraw() {
  return __cxx11::string();
}

Hand::Hand(Hand &other) {

}

Hand::~Hand() {

}

#include <iostream>
#include "controller.h"

using namespace std;

Controller::Controller(
        vector<string> deck1,
        vector<string> deck2,
        string player1Name,
        string player2Name) {
  cout << player1Name << player2Name << endl;
}

void Controller::play(int card) {
  cout << "play " << card << endl;
}

void Controller::play(int card, int playerTarget, int cardTarget) {
  cout << "play " << card << " " << playerTarget << " " << cardTarget << endl;
}

void Controller::use(int card) {
  cout << "use " << card;
}

void Controller::use(int card, int playerTarget, int cardTarget) {
  cout << "use " << card << " " << playerTarget << " " << cardTarget << endl;
}

void Controller::attack(int minion) {
  cout << "attack " << minion;

}

void Controller::attack(int minion, int otherMinion) {
  cout << "attack " << minion << " " << otherMinion << endl;

}

void Controller::drawInspect(int minion) {
  cout << "inspect " << minion << endl;

}

void Controller::drawHand() {
  cout << "hand " << endl;

}

void Controller::drawBoard() {
  cout << "board " << endl;

}

void Controller::nextTurn() {
  cout << "end " << endl;

}

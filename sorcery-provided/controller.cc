#include <iostream>
#include "controller.h"

using namespace std;

Controller::Controller(
        vector<string> deck1,
        vector<string> deck2,
        const string &player1Name,
        const string &player2Name )
        : board{make_unique<Board>(deck1,deck2,player1Name,player2Name)}
{}

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
  board->injure(board->opponent(), board->getMinion(board->whoseTurn(), minion)->getAtk());
}

void Controller::attack(int minion, int otherMinion) {
  int minionAtk = board->getMinion(board->whoseTurn(), minion)->getAtk();
  int otherMinionAtk = board->getMinion(board->opponent(), otherMinion)->getAtk();
  board->injure(board->opponent(), minionAtk, otherMinion);
  board->injure(board->whoseTurn(), otherMinionAtk, minion);
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

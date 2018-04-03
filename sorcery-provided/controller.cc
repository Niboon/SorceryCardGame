#include <iostream>
#include "controller.h"

using namespace std;

Controller::Controller( vector<string> deck1,
                        vector<string> deck2,
                        const string &player1Name,
                        const string &player2Name,
                        vector<string> loader)
        : board{make_unique<Board>(deck1,deck2,player1Name,player2Name,loader)}
{}

void Controller::play(int card) {
  board->play(board->whoseTurn(), card);
  cout << "play " << card << endl;
}

void Controller::play(int card, int playerTarget, int cardTarget) {
  board->play(board->whoseTurn(), card, playerTarget, cardTarget);
  cout << "play " << card << " " << playerTarget << " " << cardTarget << endl;
}

void Controller::use(int card) {
  board->use(board->whoseTurn(), card);
  cout << "use " << card;
}

void Controller::use(int card, int playerTarget, int cardTarget) {
  board->use(board->whoseTurn(), card, playerTarget, cardTarget);
  cout << "use " << card << " " << playerTarget << " " << cardTarget << endl;
}

void Controller::attack(int minion) {
  board->changeLife(board->opponent(), board->getMinion(board->whoseTurn(), minion)->getAtk());
}

void Controller::attack(int minion, int otherMinion) {
  int minionAtk = board->getMinion(board->whoseTurn(), minion)->getAtk();
  int otherMinionAtk = board->getMinion(board->opponent(), otherMinion)->getAtk();
  board->changeDef(board->opponent(), minionAtk, otherMinion);
  board->changeDef(board->whoseTurn(), otherMinionAtk, minion);
}

void Controller::drawInspect(int minion) {
  cout << "inspect " << minion << endl;
  card_template_t lines = board->inspect(board->whoseTurn(), minion);
  for (const auto &line: lines) {
    cout << line << endl;
  }

}

void Controller::drawHand() {
  const card_template_t &lines = board->showHand(board->whoseTurn());
  for (const auto &line: lines) {
    cout << line << endl;
  }
}

void Controller::drawBoard() {
  board->getDraw();
  cout << "board " << endl;

}

void Controller::nextTurn() {
  board->endTurn();
  board->drawCard(board->whoseTurn());
  cout << "end " << endl;

}

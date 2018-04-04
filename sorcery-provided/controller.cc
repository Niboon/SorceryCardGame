#include "controller.h"
#include "display.h"

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
  drawBoard();
}

void Controller::play(int card, int playerTarget, int cardTarget) {
  board->play(board->whoseTurn(), card, playerTarget, cardTarget);
  drawBoard();
}

void Controller::use(int card) {
  board->use(board->whoseTurn(), card);
  drawBoard();
}

void Controller::use(int card, int playerTarget, int cardTarget) {
  board->use(board->whoseTurn(), card, playerTarget, cardTarget);
  drawBoard();
}

void Controller::attack(int minion) {
  board->changeLife(board->opponent(), board->getMinion(board->whoseTurn(), minion)->getAtk());
  drawBoard();
}

void Controller::attack(int minion, int otherMinion) {
  int minionAtk = board->getMinion(board->whoseTurn(), minion)->getAtk();
  int otherMinionAtk = board->getMinion(board->opponent(), otherMinion)->getAtk();
  board->changeDef(board->opponent(), minionAtk, otherMinion);
  board->changeDef(board->whoseTurn(), otherMinionAtk, minion);
  drawBoard();
}

void Controller::drawInspect(int minion) {
  card_template_t lines = board->inspect(board->whoseTurn(), minion);
  draw(lines);
}

void Controller::drawHand() {
  const card_template_t &lines = board->showHand(board->whoseTurn());
  draw(lines);
}

void Controller::drawBoard() {
  const card_template_t &lines = board->getDraw();
  draw(lines);
}

void Controller::nextTurn() {
  board->endTurn();
  board->drawCard(board->whoseTurn());
}

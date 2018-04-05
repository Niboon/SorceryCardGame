#include "controller.h"
#include "display.h"

using namespace std;

Controller::Controller(std::vector<std::string> deck1, std::vector<std::string> deck2, const std::string &player1Name,
                       const std::string &player2Name, std::vector<std::string> loader, bool testing)
        : board{make_unique<Board>(deck1,deck2,player1Name,player2Name,loader,testing)},
          testing {testing}
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
  if (!board->hasMinion(board->whoseTurn(), card) ||
      !board->hasAction(board->whoseTurn(), card))
    return;
  board->use(board->whoseTurn(), card);
  drawBoard();
}

void Controller::use(int card, int playerTarget, int cardTarget) {
  if (!board->hasMinion(board->whoseTurn(), card) ||
      !board->hasAction(board->whoseTurn(), card))
    return;
  board->use(board->whoseTurn(), card, playerTarget, cardTarget);
  drawBoard();
}

void Controller::attack(int minion) {
  if (!board->hasMinion(board->whoseTurn(), minion) ||
      !board->hasAction(board->whoseTurn(), minion))
    return;
  board->changeLife(board->opponent(), -(board->getMinion(board->whoseTurn(), minion)->getAtk()));
  board->setAction(board->whoseTurn(), minion, false);
  drawBoard();
}

void Controller::attack(int minion, int otherMinion) {
  if (!board->hasMinion(board->whoseTurn(), minion) ||
      !board->hasMinion(board->opponent(), minion) ||
      !board->hasAction(board->whoseTurn(), minion))
    return;
  int minionAtk = board->getMinion(board->whoseTurn(), minion)->getAtk();
  int otherMinionAtk = board->getMinion(board->opponent(), otherMinion)->getAtk();
  board->changeDef(board->opponent(), -minionAtk, otherMinion);
  board->changeDef(board->whoseTurn(), -otherMinionAtk, minion);
  drawBoard();
}

void Controller::discard(int card) {
  board->discard(board->whoseTurn(),card);
  drawHand();
}

void Controller::drawCard() {
  board->drawCard(board->whoseTurn());
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
  board->startTurn();
}

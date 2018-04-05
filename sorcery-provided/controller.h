#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <vector>
#include "board.h"


class Controller {
private:
  std::unique_ptr<Board> board;
  bool testing;
public:
  Controller(std::vector<std::string> deck1, std::vector<std::string> deck2, const std::string &player1Name,
               const std::string &player2Name, std::vector<std::string> loader, bool testing);

  void play(int card);

  void play(int card, int playerTarget, int cardTarget);

  void use(int card);

  void use(int card, int playerTarget, int cardTarget);

  void attack(int minion);

  void attack(int minion, int otherMinion);

  void discard(int card);

  void drawCard();

  void drawInspect(int minion);

  void drawHand();

  void drawBoard();

  void nextTurn();
};


#endif //CONTROLLER_H

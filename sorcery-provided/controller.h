#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <vector>


class Controller {
private:
//    Board *board;
public:
  Controller(std::vector<std::string> deck1, std::vector<std::string> deck2, std::string player1Name,
             std::string player2Name);

  void play(int card);

  void play(int card, int playerTarget, int cardTarget);

  void use(int card);

  void use(int card, int playerTarget, int cardTarget);

  void attack(int minion);

  void attack(int minion, int otherMinion);

  void drawInspect(int minion);

  void drawHand();

  void drawBoard();

  void nextTurn();
};


#endif //CONTROLLER_H

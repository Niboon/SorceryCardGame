#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "interpret.h"

using namespace std;

bool processLineOfCmd(const string &line, Controller game) {// processes commands by single lines
  stringstream ss(line);
  string cmd;
  ss >> std::ws;
  ss >> cmd;
  if (cmd == "play") {
    int card, targetPlayer, targetCard;
    bool hasTargets = handleActionWith2Targets(ss, card, targetPlayer, targetCard);
    if (hasTargets)
      game.play(card, targetPlayer, targetCard);
    else
      game.play(card);
  } else if (cmd == "attack") {
    int attacker, defender;
    bool hasTargets = handleActionWith1Target(ss, cmd, attacker, defender);
    if (hasTargets)
      game.attack(attacker, defender);
    else
      game.attack(attacker);
  } else if (cmd == "use") {
    int card, targetPlayer, targetCard;
    bool hasTargets = handleActionWith2Targets(ss, card, targetPlayer, targetCard);
    if (hasTargets)
      game.use(card, targetPlayer, targetCard);
    else
      game.use(card);
  } else if (cmd == "inspect") {
    int minion;
    if (ss >> minion) {
      game.drawInspect(minion);
    }
  } else if (cmd == "hand") {
    game.drawHand();
  } else if (cmd == "board") {
    game.drawBoard();
  } else if (cmd == "end") {
    game.nextTurn();
  } else if (cmd == "quit") {
    return false;
  } else {
    // unknown command
    cerr << cmd << " Ignored: Invalid Command" << endl;
  }
  return true;
}

bool handleActionWith1Target(stringstream &ss, const string &cmd, int &card, int &targetCard) {
  bool hasTarget = false;
  ss >> std::skipws;
  if (ss >> card) {
    ss >> std::ws;
    if (ss.eof()) {
    } else {
      if (ss >> targetCard) {
        hasTarget = true;
      } else {
        cerr << " Ignored: Invalid target" << endl;
      }
    }
  }
  return hasTarget;
}

bool handleActionWith2Targets(std::stringstream &ss, int &card, int &targetPlayer, int &targetCard) {
  bool hasTargets = false;
  ss >> std::skipws;
  if (ss >> card) {
    if (ss.eof()) {
    } else {
      if (ss >> targetPlayer && ss >> targetCard) {
        hasTargets = true;
      } else {
        cerr << "Ignored: Invalid targets" << endl;
      }
    }
  }
  return hasTargets;
}

vector<string> readFileToVector(const string &filename) {
  ifstream fin;
  fin.open(filename);
  if (!fin) {
    throw invalid_argument("Cannot open given file named " + filename);
  }
  vector<string> vec;
  string line;
  fin >> std::ws;
  while (getline(fin, line)) {
    fin >> std::ws;
    vec.emplace_back(line);
  }
  fin.close();
  return vec;
}

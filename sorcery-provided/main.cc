#include <iostream>
#include <vector>
#include "interpret.h"

using namespace std;

int main(int argc, char *argv[]) {
  cin.exceptions(ios::eofbit | ios::failbit);

  string deckFile1 = "default.deck";
  string deckFile2 = "default.deck";
  string loaderFile = "loader.in";
  string initFile;

  for (int i = 1; i < argc; ++i) {
    string argument = argv[i];
    if (argument == "-deck1") {
      ++i;
      deckFile1 = argv[i];
    } else if (argument == "-deck2") {
      ++i;
      deckFile2 = argv[i];
    } else if (argument == "-init") {
      ++i;
      initFile = argv[i];
    } else if (argument == "-loader") {
      ++i;
      loaderFile = argv[i];
    } else if (argument == "-testing") {
      // Enable discard and draw inputs
      // Disable Magic Requirement
      // Disable deck shuffle
    } else {
      cerr << argument << " Ignored: Invalid Argument" << endl;
    }
  }

  // construct Controller with deck1 and deck2 as vectors of strings
  vector<string> deck1, deck2, cardLoader, init;
  try {
    deck1 = readFileToVector(deckFile1);
    deck2 = readFileToVector(deckFile2);
    cardLoader = readFileToVector(loaderFile);
    if (!initFile.empty()) {
      init = readFileToVector(initFile);
    }
  } catch (const invalid_argument &e) {
    cerr << e.what();
    exit(1);
  }

  string player1Name = "Player 1";
  string player2Name = "Player 2";
  for (auto it = init.begin(); it != init.begin() + 2; ++it) {
    auto i = distance(init.begin(), it);
    if (i == 0) {
      player1Name = *it;
    } else if (i == 1) {
      player2Name = *it;
    }
  }

  Controller game{deck1, deck2, player1Name, player2Name, cardLoader};

  for (auto it = init.begin() + 2; it != init.end(); ++it) {
    processLineOfCmd(*it, game);
  }

  cin >> std::ws; // Flush buffer of whitespace
  string line;
  try {
    while (true) {
      getline(cin, line);
      if (!processLineOfCmd(line, game)) break;
    }
  }
  catch (ios::failure &e) {
    cerr << e.what() << "I/O failure, Quit Program";
  }  // Any I/O failure quits
}

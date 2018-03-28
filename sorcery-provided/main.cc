#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "ascii_graphics.h"

std::vector<std::string> readFileToVector(const std::string &filename);

bool handleActionWith1Target(std::stringstream &ss, const std::string &cmd, int &card, int &targetCard);

bool handleActionWith2Targets(std::stringstream &ss, const std::string &cmd, int &card, int &targetPlayer,
                              int &targetCard);

bool processLineOfCmd(const std::string &line);

using namespace std;

int main(int argc, char *argv[]) {
    cin.exceptions(ios::eofbit|ios::failbit);

    string deckFile1 = "default.deck";
    string deckFile2 = "default.deck";
    string initFile;

    for (int i = 1; i < argc; ++i){
        string argument = argv[i];
        if (argument == "-deck1") {
            ++i;
            deckFile1= argv[i];
        }
        else if (argument == "-deck2") {
            ++i;
            deckFile2= argv[i];
        }
        else if (argument == "-init") {
            ++i;
            initFile = argv[i];
        }
        else if (argument == "-testing") {
            // Enable discard and draw inputs
            // Disable Magic Requirement
            // Disable deck shuffle
        }
        else {
            cerr << argument << " Ignored: Invalid Argument" << endl;
        }
    }

    // construct Controller with deck1 and deck2 as vectors of strings
    vector<string> deck1, deck2, init;
    try {
        deck1 = readFileToVector(deckFile1);
        deck2 = readFileToVector(deckFile2);
        if (!initFile.empty()) {
            init = readFileToVector(initFile);
        }
    } catch(const invalid_argument &e) {
        cerr << e.what();
        exit(1);
    }
    string player1Name = "Player 1";
    string player2Name = "Player 2";
    for (auto it=init.begin(); it!=init.end(); ++it) {
        auto i = distance(init.begin(), it);
        if (i==0) {
            player1Name = *it;
            cout << player1Name << endl;
        } else if (i==1) {
            player2Name = *it;
            cout << player2Name << endl;
        } else {
            processLineOfCmd(*it);
        }
    }
    // Controller game{deck1, deck2, player1Name, player2Name};

    cin >> std::ws; // Flush buffer of whitespace
    string line;
    try {
        while (true) {
            getline(cin, line);
            if (!processLineOfCmd(line)) break;
        }
    }
    catch (ios::failure &e) {
        cerr << e.what() << "I/O failure, Quit Program";
    }  // Any I/O failure quits
}

bool processLineOfCmd(const string &line) {// processes commands by single lines
    stringstream ss(line);
    string cmd;
    ss >> std::ws;
    ss >> cmd;
    if (cmd == "play") {
        int card, targetPlayer, targetCard;
        bool hasTargets = handleActionWith2Targets(ss, cmd, card, targetPlayer, targetCard);
        cout << endl;
    }
    else if (cmd == "attack") {
        int attacker, defender;
        bool hasTargets = handleActionWith1Target(ss, cmd, attacker, defender);
        cout << endl;
    }
    else if (cmd == "use") {
        int card, targetPlayer, targetCard;
        bool hasTargets = handleActionWith2Targets(ss, cmd, card, targetPlayer, targetCard);
        cout << endl;
    }
    else if (cmd == "inspect") {
        int minion;
        if (ss >> minion) {
            // game.drawInspect(minion);
            cout << cmd << minion << endl;
        }
    }
    else if (cmd == "hand") {
        // game.drawHand();
        cout << cmd << endl;
    }
    else if (cmd == "board") {
        // game.drawBoard();
        cout << cmd << endl;
    }
    else if (cmd == "end") {
        // game.nextTurn();
        cout << cmd << endl;
    }
    else if (cmd == "quit") {
        cout << cmd << endl;
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
            cout << cmd << card;
        } else {
            if (ss >> targetCard) {
                cout << cmd << card << targetCard;
                hasTarget = true;
            } else {
                cerr << cmd << " Ignored: Invalid target" << endl;
            }
        }
    }
    return hasTarget;
}

bool handleActionWith2Targets(stringstream &ss, const string &cmd, int &card, int &targetPlayer, int &targetCard) {
    bool hasTargets = false;
    ss >> std::skipws;
    if (ss >> card) {
        if (ss.eof()) {
            cout << cmd << card;
        } else {
            if (ss >> targetPlayer && ss >> targetCard) {
                cout << cmd << card << targetPlayer << targetCard;
                hasTargets = true;
            } else {
                cerr << cmd << " Ignored: Invalid targets" << endl;
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

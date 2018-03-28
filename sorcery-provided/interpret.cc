#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "interpret.h"

using namespace std;

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

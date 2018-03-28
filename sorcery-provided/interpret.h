#ifndef INTERPRET_H
#define INTERPRET_H

std::vector<std::string> readFileToVector(const std::string &filename);

bool handleActionWith1Target(std::stringstream &ss, const std::string &cmd, int &card, int &targetCard);

bool handleActionWith2Targets(std::stringstream &ss, const std::string &cmd, int &card, int &targetPlayer,
                              int &targetCard);

bool processLineOfCmd(const std::string &line);

#endif //INTERPRET_H

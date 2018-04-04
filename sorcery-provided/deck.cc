#include <sstream>
#include <map>
#include <algorithm>
#include <ctime>
#include "deck.h"
#include "creature.h"
#include "statsEnchantmentCard.h"
#include "abilityEnchantmentCard.h"
#include "spell.h"
//#include "ritual.h"
//#include "spell.h"
#include "board.h"

using namespace std;

Deck::Deck(vector<string> cardNames, vector<string> loader) {
  for (const auto &cardName : cardNames) {
    for (const auto &line : loader) {
      stringstream ss(line);
      string cmd, name;
      ss >> std::ws >> cmd;
      name = cmd;
      replace(name.begin(), name.end(), '_', ' '); // Replace _ with space so it matches the deck naming
      if (cardName != name) continue; // Skips this line if it doesn't match this cardName
      // Otherwise, create the card and add it to the Deck's cards
      map<string, string> cardParams;
      while (!ss.eof()) {
        ss >> std::ws >> cmd;
        insertPair(cardParams, cmd, ss);
      }
      loadCard(name, cardParams, cards);
    }
  }

//  shuffleDeck();
}

// Shuffles deck of cards
// Seeds rand using time, random address and an optional nonce to minimize synchronised shuffles
void Deck::shuffleDeck(int nonce) {
  auto randomAddress = vector<int>{1,1,3,4};
  int *pInt = randomAddress.data();
  const auto saltFromAddress = reinterpret_cast<size_t>(pInt); // reinterpret_cast purely to get salt
  const auto timeDerived = (2^nonce) * time(nullptr);
  const auto seed = static_cast<unsigned int>(timeDerived ^ saltFromAddress);
  srand(seed);
  random_shuffle(cards.begin(), cards.end());
}

int Deck::getSize() const {
  return static_cast<int>(cards.size());
}

unique_ptr<Card> Deck::popCard() {
  if (!cards.empty()) {
    unique_ptr<Card> ret{move(cards.back())};
    cards.pop_back();
    return move(ret);
  }
  return nullptr;
}

void Deck::pushCard(unique_ptr<Card> newCard) {
  cards.emplace_back(move(newCard));
  shuffleDeck();
}

void loadCard(const string &name, map<string, string> &cardParams, vector<unique_ptr<Card>> &deckCards) {
  basic_string<char> &type = cardParams.at("type");
  if (type == "Minion") {
    deckCards.emplace_back(
            make_unique<Creature>(
                    name,
                    stoi(cardParams["cost"]),
                    stoi(cardParams["atk"]),
                    stoi(cardParams["def"]),
                    0
            )
    );
  } else if (type == "TriggerMinion") {
    deckCards.emplace_back(
            make_unique<Creature>(
                    name,
                    stoi(cardParams["cost"]),
                    stoi(cardParams["atk"]),
                    stoi(cardParams["def"]),
                    0
            )
    );
  } else if (type == "AbilityMinion") {
    deckCards.emplace_back(
            make_unique<Creature>(
                    name,
                    stoi(cardParams["cost"]),
                    stoi(cardParams["atk"]),
                    stoi(cardParams["def"]),
                    0
            )
    );
  } else if (type == "Spell") {
    unique_ptr<Ability> ability = loadAbility(cardParams);
    deckCards.emplace_back(
            make_unique<Spell>(
                    name,
                    stoi(cardParams["cost"]),
                    move(ability)
            )
    );
  } else if (type == "StatsEnchantment") {
    deckCards.emplace_back(
            make_unique<StatsEnchantmentCard>(
                    name,
                    stoi(cardParams["cost"]),
                    stoi(cardParams["atk"]),
                    stoi(cardParams["def"])
            )
    );
  } else if (type == "SpellEnchantment") {
    unique_ptr<Ability> ability = loadAbility(cardParams);
    deckCards.emplace_back(
            make_unique<AbilityEnchantmentCard>(
                    name,
                    stoi(cardParams["cost"]),
                    ability
            )
    );
  } else if (type == "TriggerEnchantment") {
    unique_ptr<Ability> ability = loadAbility(cardParams);
    deckCards.emplace_back(
            make_unique<AbilityEnchantmentCard>(
                    name,
                    stoi(cardParams["cost"]),
                    ability
            )
    );
  } else if (type == "Ritual") {
    unique_ptr<Ability> ability = loadAbility(cardParams);
    deckCards.emplace_back(
            make_unique<Ritual>(
                    name,
                    stoi(cardParams["cost"]),
                    ability,
                    stoi(cardParams["charges"])
            )
    );
  }
}

unique_ptr<Ability> loadAbility(map<string, string> &cardParams) {
  void (*effectPtr)(Board *b, int tP, int tS) = [](Board *b, int tP, int tS){ return;};
  basic_string<char> &target = cardParams.at("target");
  if (target == "Given") {
    if (cardParams.count("effect")) { // Effects without an additional value
      if (cardParams.at("effect") == "destroy") {
        effectPtr = [](Board *b, int tP, int tS) { b->destroy(tP, tS); };
      } else if (cardParams.at("effect") == "return") {
        effectPtr = [](Board *b, int tP, int tS) { b->returnToDeck(tP, tS);};
      } else if (cardParams.at("effect") == "destroyEnchantment") {
        effectPtr = [](Board *b, int tP, int tS) { b->destroyEnchantment(tP, tS);};
      }
    } else if (cardParams.count("changeAtk")) {
      if (cardParams.count("changeDef")) {
        effectPtr = [](Board *b, int tP, int tS) {
            b->changeAtk(tP, stoi(cardParams.at("changeAtk")), tS);
            b->changeDef(tP, stoi(cardParams.at("changeDef")), tS);
        };
      } else {
        effectPtr = [](Board *b, int tP, int tS) {
            b->changeAtk(tP, stoi(cardParams.at("changeAtk")), tS);
        };
      }
    } else if (cardParams.count("changeDef")) {
      effectPtr = [](Board *b, int tP, int tS) {
          b->changeDef(tP, stoi(cardParams.at("changeDef")), tS);
      };
    } else if (cardParams.count("changeMagic")) {
      effectPtr = [](Board *b, int tP, int tS) {
          b->changeMagic(tP, stoi(cardParams.at("changeMagic")));
      };
    }
  } else if (target == "Self") {
    if (cardParams.count("summon")) {
      effectPtr = [](Board *b, int tP, int tS) {
          string what = cardParams.at("summon");
          int count = stoi(what.substr(0,1));
          string name = what.substr(2);
          replace(name.begin(), name.end(), '_', ' '); // Replace _ with space so it matches the deck naming
          b->specialSummon(b->whoseTurn(), name, count);
      };
    } else if (cardParams.count("changeCharge")) {
      effectPtr = [](Board *b, int tP, int tS) {
          b->changeCharge(b->whoseTurn(), stoi(cardParams.at("changeCharge")));
      };
    } else if (cardParams.count("resurrect")) {
      effectPtr = [](Board *b, int tP, int tS) { b->resurrect(b->whoseTurn()); };
    }
  } else if (target == "SelfAll") {
    if (cardParams.count("changeAtk")) {
      if (cardParams.count("changeDef")) {
        effectPtr = [](Board *b, int tP, int tS) {
            b->changeAtk(tP, stoi(cardParams.at("changeAtk")));
            b->changeDef(tP, stoi(cardParams.at("changeDef")));
        };
      } else {
        effectPtr = [](Board *b, int tP, int tS) {
            b->changeAtk(tP, stoi(cardParams.at("changeAtk")));
        };
      }
    } else if (cardParams.count("changeDef")) {
      effectPtr = [](Board *b, int tP, int tS) {
          b->changeDef(tP, stoi(cardParams.at("changeDef")));
      };
    }
  } else if (target == "All") {
    if (cardParams.count("changeAtk")) {
      if (cardParams.count("changeDef")) {
        effectPtr = [](Board *b, int tP, int tS) {
            b->changeAtk(stoi(cardParams.at("changeAtk")));
            b->changeDef(stoi(cardParams.at("changeDef")));
        };
      } else {
        effectPtr = [](Board *b, int tP, int tS) {
            b->changeAtk(stoi(cardParams.at("changeAtk")));
        };
      }
    } else if (cardParams.count("changeDef")) {
      effectPtr = [](Board *b, int tP, int tS) {
          b->changeDef(stoi(cardParams.at("changeDef")));
      };
    }
  }

  unique_ptr<Ability> ability{cardParams["desc"], effectPtr};
  return move(ability);
}

void insertPair(map<string, string> &params, const string &cmd, stringstream &ss) {
  const string &key = cmd.substr(1);
  string val;
  ss >> ws >> val;
  replace(val.begin(), val.end(), '_', ' '); // Replace _ with space
  params[key] = val;
}

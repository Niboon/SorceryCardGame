#include <sstream>
#include <map>
#include <algorithm>
#include <ctime>
#include "deck.h"
#include "creature.h"
#include "statsEnchantmentCard.h"
#include "abilityEnchantmentCard.h"
//#include "ritual.h"
//#include "spell.h"

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

  shuffleDeck();
}

// Shuffles deck of cards
// Seeds rand using time, cards' address and an optional nonce to minimize synchronised shuffles
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
//    deckCards.emplace_back(
//            make_unique<Spell>(
//                    name,
//                    stoi(cardParams["cost"]),
//                    cardParams["desc"],
//                    stoi(cardParams["abilityCost"]),
//                    stoi(cardParams["ability"])
//            )
//    );
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
    deckCards.emplace_back(
            make_unique<AbilityEnchantmentCard>(
                    name,
                    stoi(cardParams["cost"]),
                    0
            )
    );
  } else if (type == "TriggerEnchantment") {
    deckCards.emplace_back(
            make_unique<AbilityEnchantmentCard>(
                    name,
                    stoi(cardParams["cost"]),
                    0
            )
    );
  } else if (type == "Ritual") {
//    deckCards.emplace_back(
//            make_unique<Ritual>(
//                    name,
//                    stoi(cardParams["cost"]),
//                    stoi(cardParams["triggerAbility"]),
//                    stoi(cardParams["charges"])
//            )
//    );
  }
}

void insertPair(map<string, string> &params, const string &cmd, stringstream &ss) {
  const string &key = cmd.substr(1);
  string val;
  ss >> ws >> val;
  replace(val.begin(), val.end(), '_', ' '); // Replace _ with space
  params[key] = val;
}

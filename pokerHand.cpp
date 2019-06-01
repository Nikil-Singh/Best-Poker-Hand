#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include "handClass.hpp"

//Tokenises strings by space into a vector.
vector<string> tokeniseString(string cards);
vector<Card> generateHand(string cards);
bool checkCard(string card);
bool checkSuit(string suit);
bool checkRank(string rank);

int main() {
    string cards;
    cout << "Enter Cards: ";
    getline(cin, cards);
    vector<Card> hand = generateHand(cards);
    cout << "Successful\n";
    return 0;
}

vector<Card> generateHand(string cards) {
    vector<string> newCards = tokeniseString(cards);
    vector<Card> hand;
    for (int i = 0; i < newCards.size(); i++) {
        if (checkCard(newCards[i])) {
            Card card(0, "H");
            hand.push_back(card);
        } else {
            exit(2);
        }
    }
    return hand;
}

//Tokenises strings by space into a vector.
vector<string> tokeniseString(string cards) {
    vector<string> tokens;
    istringstream ss(cards);
    string s;
    //Tokenises the string.
    while (getline(ss, s, ' ')) tokens.push_back(s);
    return tokens;
}

bool checkCard(string card) {
    //Checks if card string length is appropriate.
    if (!(card.length() >= 2 && card.length() <= 3)) {
        cout << card << " is of inappropriate length for a card. Length must be between 2 and 3.\n";
        return false;
    }

    //Sets up variables based on length of string.
    string suit, rank = "";
    if (card.length() == 2) {
        suit = card.substr(1,1);
        rank = card.substr(0,1);
    } else {
        suit = card.substr(2,2);
        rank = card.substr(0,2);
    }

    if (!checkSuit(suit)) return false;
    if (!checkRank(rank)) return false;
    return true;
}

//Checks if the suit is valid.
bool checkSuit(string suit) {
    if (!(!suit.compare("C") || !suit.compare("D") || !suit.compare("H")
        || !suit.compare("S"))) {

        cout << suit << " is not a valid suit.\n";
        return false;
    }
    return true;
}

//Checks if the rank is valid.
bool checkRank(string rank) {
    int nRank = 0;
    if (!(!rank.compare("A") || !rank.compare("K") || !rank.compare("Q")
        || !rank.compare("J"))) {
        //If rank is not A, K, Q, or J then check if it is a number.
        try {
            nRank = stoi(rank);
        } catch(invalid_argument& e) {
            cout << rank << " is not a valid rank.\n";
            return false;
        }
        //Checks for range of range between 2 and 10.
        if (nRank < 2 || nRank > 10) {
            cout << nRank << " is out of range from between 2 and 10.\n";
            return false;
        }
    }
    return true;
}

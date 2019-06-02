#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include "handClass.hpp"

//Generates a vector of cards to construct a hand.
vector<Card> generateHand(string cards);
//Tokenises strings by space into a vector.
vector<string> tokeniseString(string cards);
//Checks for duplicate cards.
void checkDuplicateCards(vector<Card> hand);
//Gets rid of leading and trailing whitespace.
string trim(string cards);
//Reduces spacing between cards to be one, to prepare for tokenisation.
string setUpForTokenisation(string cards);
//Gets string for rank.
string retrieveRank(string card);
//Gets string for suit.
string retrieveSuit(string card);
//Determines if string can be converted into a card.
bool checkCard(string card);
//Checks if the suit is valid.
bool checkSuit(string suit);
//Checks if the rank is valid.
bool checkRank(string rank);

int main() {
    string cards;
    cout << "Enter Cards: ";
    getline(cin, cards);
    if (cards.empty()) {
        cout << "No input was detected.\n";
        return 0;
    }
    vector<Card> tmpHand = generateHand(cards);
    Hand hand(tmpHand);
    hand.printCards();
    string test = hand.bestHand();
    cout << test;
    return 0;
}

//Generates a vector of cards to construct a hand.
vector<Card> generateHand(string cards) {
    vector<string> newCards = tokeniseString(cards);
    //Checks if a valid number of cards has been entered.
    if (newCards.size() < 2 || newCards.size() > 7) {
        cout << newCards.size() << " is an inappropriate number of cards. Number of cards must be between 2 to 7.\n";
        exit(2);
    }
    vector<Card> hand;
    //Checks if cards are valid and places them into a vector.
    for (int i = 0; i < newCards.size(); i++) {
        if (checkCard(newCards[i])) {
            Card card(retrieveRank(newCards[i]), retrieveSuit(newCards[i]));
            hand.push_back(card);
        } else {
            exit(2);
        }
    }
    //Checks if any duplicate cards have been entered.
    checkDuplicateCards(hand);
    return hand;
}

//Tokenises strings by space into a vector.
vector<string> tokeniseString(string cards) {
    vector<string> tokens;
    string newCards = trim(cards);
    newCards = setUpForTokenisation(newCards);
    istringstream ss(newCards);
    string s;
    //Tokenises the string.
    while (getline(ss, s, ' ')) tokens.push_back(s);
    return tokens;
}

//Checks for duplicate cards.
void checkDuplicateCards(vector<Card> hand) {
    vector<string> seen;
    for (int i = 0; i < hand.size(); i++) {
        if (seen.empty() && !(hand.empty())) {
            seen.push_back(hand[i].returnString());
            continue;
        } else if (find(seen.begin(), seen.end(), hand[i].returnString()) != seen.end()) {
            cout << hand[i].returnString() << " has more than one instance, there can be no duplicate cards.\n";
            exit(2);
        } else {
            seen.push_back(hand[i].returnString());
        }
    }
}

//Gets rid of leading and trailing whitespace.
string trim(string cards) {
    return cards.substr(cards.find_first_not_of(" \t"), cards.find_last_not_of(" \t") + 1);
}

//Reduces spacing between cards to be one, to prepare for tokenisation.
string setUpForTokenisation(string cards) {
    for (int i = 0; i < cards.length(); i++) {
        if ((i < (cards.length() - 1)) && (cards[i] == ' ') && (cards[i+1] == ' ')) {
            cards.erase(i,1);
        }
    }
    return cards;
}

//Gets string for rank.
string retrieveRank(string card) {
    //Sets up variables based on length of string.
    string rank = "";
    if (card.length() == 2) {
        rank = card.substr(0,1);
    } else {
        rank = card.substr(0,2);
    }
    return rank;
}

//Gets string for suit.
string retrieveSuit(string card) {
    //Sets up variables based on length of string.
    string suit = "";
    if (card.length() == 2) {
        suit = card.substr(1,1);
    } else {
        suit = card.substr(2,2);
    }
    return suit;
}

//Determines if string can be converted into a card.
bool checkCard(string card) {
    //Checks if card string length is appropriate.
    if (!(card.length() >= 2 && card.length() <= 3)) {
        cout << card << " is of inappropriate length for a card. Length must be between 2 and 3.\n";
        return false;
    }

    //Sets up variables based on length of string.
    string suit = retrieveSuit(card);
    string rank = retrieveRank(card);

    //Checks if rank and suit is valid.
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

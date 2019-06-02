#include "cardClass.hpp"

//Constructor
Card::Card(string newRank, string newSuit) {
    _rank = newRank;
    _suit = newSuit;
}

//Returns rank.
string Card::getRank() {
    return _rank;
}

//Returns suit
string Card::getSuit() {
    return _suit;
}

//Returns card as a string.
string Card::returnString() {
    return getRank() + getSuit();
}

int Card::convertRankToNum(string rank) {
    int r = 0;
    if (!rank.compare("A")) {
        r = 14;
    } else if (!rank.compare("K")) {
        r = 13;
    } else if (!rank.compare("Q")) {
        r = 12;
    } else if (!rank.compare("J")) {
        r = 11;
    } else {
        r = stoi(rank);
    }
    return r;
}

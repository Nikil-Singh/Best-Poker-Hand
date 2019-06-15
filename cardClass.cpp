#include "cardClass.hpp"

//Constructor
Card::Card(string newRank, string newSuit) {
    _rank = convertRankToNum(newRank);
    _suit = newSuit;
}

//Returns rank.
int Card::getRank() {
    return _rank;
}

//Returns suit
string Card::getSuit() {
    return _suit;
}

//Returns card as a string.
string Card::returnString() {
    string rank = "";
    int r = getRank();
    if (r <= 10) {
        rank = to_string(r);
    } else {
        switch(r) {
            case 14 : rank = "A"; break;
            case 13 : rank = "K"; break;
            case 12 : rank = "Q"; break;
            case 11 : rank = "J"; break;
        }
    }
    return rank + getSuit();
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

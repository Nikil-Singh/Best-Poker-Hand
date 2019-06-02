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

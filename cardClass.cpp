#include "cardClass.hpp"

Card::Card(int newRank, string newSuit) {
    _rank = newRank;
    _suit = newSuit;
}

int Card::getRank() {
    return _rank;
}

string Card::getSuit() {
    return _suit;
}

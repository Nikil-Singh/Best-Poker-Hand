#include "handClass.hpp"

//Constructor
Hand::Hand(vector<Card> hand) {
     _cards = hand;
}

//Returns hand.
vector<Card> Hand::getHand() {
    return _cards;
}
//Prints out cards
void Hand::printCards() {
    vector<Card> hand = getHand();
    for (int i = 0; i < hand.size(); i++) {
        cout << hand[i].returnString() << " ";
    }
    cout << "\n";
}

//Determines and returns the best poker hand.
string Hand::bestHand() {
    //Gets a hand that is sorted numerically in descending order.
    vector<Card> hand = sortHand();
    string finalHand = "";

    //First checks hands that require at least 5 cards.
    if (hand.size() >= 5) {
        string flushSuit = flush(hand);
        //If a flush is possible.
        if (flushSuit.compare(" ")) {
            //Gets a vector containing only the highest ranking 5 cards with
            //suit that results in a flush.
            vector<Card> flushSet;
            for (int i = 0; i < 5; i++) {
                if (!((hand[i].getSuit()).compare(flushSuit))) {
                    flushSet.push_back(hand[i]);
                }
            }
            //Finds highest straight.
            int straightStart = straight(flushSet);
            if (straightStart != -1 && (flushSet[straightStart].getRank() == 14)) {
                //Check if royal flush.
                cout << "Royal Flush\n";
                for (int i = straightStart; i < flushSet.size(); i++) {
                    cout << flushSet[i].returnString() << " ";
                }
                cout << "\n";

            } else if (straightStart != -1 && (flushSet[straightStart].getRank() != 14)) {
                //Check if straight flush.
                cout << "Straight Flush\n";
                for (int i = straightStart; i < flushSet.size(); i++) {
                    cout << flushSet[i].returnString() << " ";
                }
                cout << "\n";

            } else {
                //Thus it is only a flush.
                cout << "Flush\n";
                for (int i = 0; i < flushSet.size(); i++) {
                    cout << flushSet[i].returnString() << " ";
                }
                cout << "\n";
            }

        } else {
            //Check if full house.
            int triples = triple(hand);
            vector<int> pairs = pair(hand);
            if (triples != -1 && !pairs.empty()) {
                int found = -1;
                for (int i = 0; i < pairs.size(); i++) {
                    if (triples != pairs[i]) {
                        found = i;
                        break;
                    }
                }
                if (found != -1) {
                    vector<Card> fullHouse;
                    for (int i = 0; i < hand.size(); i++) {
                        //cout << "triple: " << triples.substr(0,1) << "\n";
                        if (hand[i].getRank() == triples || hand[i].getRank() == pairs[found]) {
                            cout << "Pushed Back: " << hand[i].returnString() << "\n";
                            fullHouse.push_back(hand[i]);
                            cout << hand[i].returnString() << " ";
                        }
                    }
                    cout << "\n";
                }
                cout << "Triple: " << triples << "\n";
                cout << "Pair: " << pairs[0] << "\n";
            }



            //Check if straight.
            int straightStart = straight(hand);
            if (straightStart != -1) {
                cout << "Straight\n";
                for (int i = straightStart; i < straightStart + 5; i++) {
                    cout << hand[i].returnString() << " ";
                }
                cout << "\n";
            }

        }
    }

    //Check if four of a kind.

    //Check if three of a kind.

    //Check if two pair.

    //Check if pair.

    //Get highest card.

    /*
    for (int i = 0; i < hand.size(); i++) cout << hand[i].returnString() << " ";
    cout << "\n";
    */
    return "";
}

//Returns a numerically sorted hand.
vector<Card> Hand::sortHand() {
    vector<Card> hand = getHand();
    bool swapped;
    for (int i = 0; i < hand.size()-1; i++) {
        swapped = false;
        for (int j = 0; j < hand.size()-i-1;j++) {
            if (hand[j].getRank() < hand[j+1].getRank()) {
                Card tmp = hand[j];
                hand[j] = hand[j+1];
                hand[j+1] = tmp;
                swapped = true;
            }
        }
        if (swapped == false) break;
    }
    return hand;
}

//Checks if there is a flush.
string Hand::flush(vector<Card> hand) {
    int c = 0, d = 0, h = 0, s = 0; //clubs, hearts, ...
    for (int i = 0; i < hand.size(); i++) {
        if (!((hand[i].getSuit()).compare("C"))) c++;
        if (!((hand[i].getSuit()).compare("D"))) d++;
        if (!((hand[i].getSuit()).compare("H"))) h++;
        if (!((hand[i].getSuit()).compare("S"))) s++;
    }
    if (c >= 5) return "C";
    if (d >= 5) return "D";
    if (h >= 5) return "H";
    if (s >= 5) return "S";
    return " ";
}

//Gets the start of a straight if it exists.
int Hand::straight(vector<Card> hand) {
    int straightCount = 1;
    int straightStart = 0;
    //Finds highest straight.
    for (int i = 0; i < hand.size()-1; i++) {
        if (hand[i].getRank()-1 == hand[i+1].getRank()) {
            straightCount++;
            if (straightCount == 5) break;
        } else {
            straightCount = 1;
            straightStart = i+1;
        }
    }
    if (straightCount == 5) return straightStart;
    return -1;
}

//Returns string of ranks that have a triple.
int Hand::triple(vector<Card> hand) {
    int triples = -1;
    int count = 1;
    for (int i = 0; i < hand.size()-1; i++) {
        //If ranks match
        if (hand[i].getRank() == hand[i+1].getRank()) {
            count++;
            if (count == 3) {
                triples = hand[i].getRank();
                break; //Can only have at most one triple in a hand.
            }
        } else {
            count = 1;
        }
    }
    return triples;
}

//Returns string of ranks that have a pair.
vector<int> Hand::pair(vector<Card> hand) {
    vector<int> pair;
    int count = 1;
    for (int i = 0; i < hand.size()-1; i++) {
        //If ranks match
        if (hand[i].getRank() == hand[i+1].getRank()) {
            cout << "Gets here: " << hand[i+1].getRank() << "\n";
            count++;
            if (count == 2) {
                if (pair.end() != find(pair.begin(), pair.end(), hand[i].getRank())) {
                    pair.push_back(hand[i].getRank());
                }
                count = 1;
            }
        } else {
            count = 1;
        }
    }
    return pair;
}

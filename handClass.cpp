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
    //Gets a hand that is sorted numerically.
    vector<Card> hand = sortHand();
    string finalHand = "";

    //First checks hands that require at least 5 cards.
    if (hand.size() >= 5) {
        string flushSuit = flush(hand);
        //If a flush is possible.
        if (flushSuit.compare(" ")) {
            //Gets a vector containing only the suit that results in a flush.
            vector<Card> flushSet;
            for (int i = 0; i < hand.size(); i++) {
                if (!((hand[i].getSuit()).compare(flushSuit))) {
                    flushSet.push_back(hand[i]);
                }
            }
            //Finds highest straight.
            int straightStart = straight(flushSet);
            if (straightStart != -1 && !((flushSet[straightStart].getRank()).compare("A"))) {
                //Check if royal flush.
                cout << "Royal Flush\n";
                for (int i = straightStart; i > straightStart-5; i--) {
                    cout << flushSet[i].returnString() << " ";
                }
                cout << "\n";

            } else if (straightStart != -1 && (flushSet[straightStart].getRank()).compare("A")) {
                //Check if straight flush.
                cout << "Straight Flush\n";
                for (int i = straightStart; i > straightStart-5; i--) {
                    cout << flushSet[i].returnString() << " ";
                }
                cout << "\n";

            } else {
                //Thus it is only a flush.
                cout << "Flush\n";
                for (int i = flushSet.size()-1; i > flushSet.size()-6; i--) {
                    cout << flushSet[i].returnString() << " ";
                }
                cout << "\n";
            }

        } else {
            //Check if full house.

            //Check if straight.

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
            if (compareHandRank(hand[j], hand[j+1])) {
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
    int straightStart = hand.size();
    string rank1 = "", rank2 = "";
    int r1 = 0, r2 = 0;
    //Finds highest straight.
    for (int i = hand.size()-1; i > 0; i--) {
        rank1 = hand[i].getRank();
        rank2 = hand[i-1].getRank();
        r1 = hand[i].convertRankToNum(rank1);
        r2 = hand[i-1].convertRankToNum(rank2);
        cout << "r1: " << r1 << " r2: "<< r2 << "\n";
        if (r1-1 == r2) {
            straightCount++;
            if (straightCount == 5) {
                straightStart = i;
                break;
            }    
        } else {
            straightCount = 1;
        }
    }
    if (straightCount == 5) return straightStart;
    return -1;
}

//Compares card ranks.
bool Hand::compareHandRank(Card card1, Card card2) {
    string rank1 = card1.getRank();
    string rank2 = card2.getRank();
    int r1 = card1.convertRankToNum(rank1);
    int r2 = card2.convertRankToNum(rank2);
    if (r1 > r2) return true;
    return false;
}

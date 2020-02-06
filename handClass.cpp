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

/*
string Hand::bestHand() {
    //Gets a hand that is sorted numerically in descending order.
    vector<Card> hand = sortHand();
    
    // First checks hands that require at least 5 cards.
    
    // If a flush is possible.
     if () {
        getHighestFlushSet();
        if RoyalFlush print
        if StraightFlush print
        else NormalFlush print
    }
    if fourOfAKind print
    if fullHouse print
    if straight print
    if threeOfAKind print
    if twoPair print
    if onePair print
    else highCard print
}
*/
/*
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
            int j = 0;
            for (int i = 0; i < hand.size(); i++) {
                if (!((hand[i].getSuit()).compare(flushSuit))) {
                    flushSet.push_back(hand[i]);
                    j++;
                }
                if (j == 5) break;
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
            //Checks for four of a kind.
            int four = fourKind(hand);
            if (four != -1) {
                vector<Card> fourOfKind;
                int max = 2;
                for (int i = 0; i < hand.size(); i++) {
                    if (hand[i].getRank() == four) {
                        fourOfKind.push_back(hand[i]);
                    }
                    if (hand[i].getRank() != four && hand[i].getRank() > max) {
                        max = hand[i].getRank();
                    }
                }
                for (int i = 0; i < hand.size(); i++) {
                    if (hand[i].getRank() == max) {
                        fourOfKind.push_back(hand[i]);
                        break;
                    }
                }
                cout << "Four of a Kind\n";
                for (int i = 0; i < fourOfKind.size(); i++) {
                    cout << fourOfKind[i].returnString() << " ";
                }
                cout << "\n";
                return "";
            }

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
                            fullHouse.push_back(hand[i]);
                        }
                    }
                    cout << "Full House\n";
                    for (int i = 0; i < fullHouse.size(); i++) {
                        cout << fullHouse[i].returnString() << " ";
                    }
                    cout << "\n";
                }
                return "";
            }

            //Check if straight.
            int straightStart = straight(hand);
            if (straightStart != -1) {
                cout << "Straight\n";
                for (int i = straightStart; i < straightStart + 5; i++) {
                    cout << hand[i].returnString() << " ";
                }
                cout << "\n";
                return "";
            }

        }
    }

    int check = 0;
    //Check if four of a kind.
    if (hand.size() == 4) {
        check = fourKind(hand);
        if (check != -1) {
            vector<Card> fourOfKind;
            for (int i = 0; i < hand.size(); i++) {
                if (hand[i].getRank() == check) {
                    fourOfKind.push_back(hand[i]);
                }
            }
            cout << "Four of a Kind\n";
            for (int i = 0; i < fourOfKind.size(); i++) {
                cout << fourOfKind[i].returnString() << " ";
            }
            cout << "\n";
            return "";
        }
    }

    //Check if three of a kind.
    if (hand.size() >= 3) {
        check = triple(hand);
        if (check != -1) {
            vector<Card> threeOfKind;
            for (int i = 0; i < hand.size(); i++) {
                if (hand[i].getRank() == check) {

                }
            }
        }
    }

    //Check if two pair or pair.
    vector<int> setPairs = pair(hand);
    if (setPairs.size() > 1) {

    } else if (setPairs.size() == 1) {

    }


    //Get highest card.

    for (int i = 0; i < hand.size(); i++) cout << hand[i].returnString() << " ";
    cout << "\n";
    
    return "";
}
*/
// Gets the best hand possible for the hand.
string Hand::bestHand() {
    //Gets a hand that is sorted numerically in descending order.
    vector<Card> hand = sortHand();
    string flushSuit = flush(hand);
    // Checks if the hand has a flush.
    if (flushSuit.compare(" ")) {
        // Gets a hand that has cards from flush.
        vector<Card> flushHand = flushedHand(hand, flushSuit);
        // Checks if hand has a straight.
        int straightStart = straight(flushHand);
        if (straightStart != -1) {
            // If straight begins with an ACE.
            if (hand[straightStart].getRank() == 14) {
                return "Royal Flush";
            } else {
                // Otherwise just a normal straight.
                return "Straight Flush";
            }
        } else {
            // If it does not contain a straight, then just its just a flush.
            cout << "Flush\n";
            return "Flush";
        }
    } else {
        // If hand does not have a flush.
        // If hand has a four of a kind. 
        int four = fourKind(hand);
        if (four != -1) {
            return "Four of a Kind";
        } 

        int triples = triple(hand);
        vector<int> pairs = pair(hand);
        // If hand has a full house.
        if (checkFullHouse(triples, pairs)) {
            return "Full House\n";
        }

        // If hand has a straight.
        int straightStartOther = straight(hand);
        if (straightStartOther != -1) {
            return "Straight";
        }

        // If hand has a three of a kind.
        if (triples != -1) {
            return "Triples";
        }

        // If hand has a two pair.
        if (pairs.size() >= 2) {
            return "Two Pair";
        }

        // If hand has a pair.
        if (pairs.size() == 1) {
            return "Single Pair";
        }

        // Otherwise we take the highest card.
        return "Highest Card";
    }
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

vector<Card> Hand::flushedHand(vector<Card> hand, string flushSuit) {
    vector<Card> newHand;
    int j = 0;
    for (int i = 0; i < hand.size(); i++) {
        if (!((hand[i].getSuit()).compare(flushSuit))) {
            newHand.push_back(hand[i]);
            j++;
        }
        if (j == 5) break;
    }
    return newHand;
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

//Gets the start (index within vector) of a straight if it exists.
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

//Returns rank of triple.
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

//Returns vector of ranks that have a pair.
vector<int> Hand::pair(vector<Card> hand) {
    vector<int> pair;
    int count = 1;
    for (int i = 0; i < hand.size()-1; i++) {
        //If ranks match
        if (hand[i].getRank() == hand[i+1].getRank()) {
            count++;
            if (count == 2) {
                if (pair.end() == find(pair.begin(), pair.end(), hand[i].getRank())) {
                    cout << "Gets here: " << hand[i].getRank() << "\n";
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

//Returns rank of four of a kind.
int Hand::fourKind(vector<Card> hand) {
    int four = -1;
    int count = 1;
    for (int i = 0; i < hand.size()-1; i++) {
        if (hand[i].getRank() == hand[i+1].getRank()) {
            count++;
            if (count == 4) {
                four = hand[i].getRank();
                break; //Can only have at most one four of a king in a hand.
            }
        } else {
            count = 1;
        }
    }
    return four;
}

// Checks if hand contains a full house.
bool Hand::checkFullHouse(int triple, vector<int> pairs) {
    bool found = false;
    if (triple != -1 && !pairs.empty()) {
        for (int i = 0; i < pairs.size(); i++) {
            if (triple != pairs[i]) {
                found = true;
                break;
            }
        }
    }
    return found;
}

// Converts hand to a string.
string Hand::handToString(vector<Card> hand) {
    string strHand = "";
    for (int i = 0; i < hand.size(); i++) {
        strHand += hand[i].returnString() + " ";
    }
    return strHand;
}

// Fills up hand with high cards if there is space.
vector<Card> fillHand(vector<Card> hand, int rank) {
    vector<Card> newHand;
    return newHand;
}
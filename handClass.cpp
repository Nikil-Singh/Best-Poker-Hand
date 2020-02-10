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

// Gets the best hand possible for the hand.
string Hand::bestHand() {
    //Gets a hand that is sorted numerically in descending order.
    vector<Card> hand = sortHand();
    string flushSuit = flush(hand);
    vector<Card> newHand;
    // Checks if the hand has a flush.
    if (flushSuit.compare(" ")) {
        // Gets a hand that has cards from flush.
        vector<Card> flushHand = flushedHand(hand, flushSuit);
        // Checks if hand has a straight.
        int straightStart = straight(flushHand);
        if (straightStart != -1) {
            newHand = fillHandStraightFlush(hand, straightStart, flushSuit);
            // If straight begins with an ACE.
            if (hand[straightStart].getRank() == 14) {
                return "Royal Flush\n" + handToString(newHand);
            } else {
                // Otherwise just a normal straight.
                return "Straight Flush\n" + handToString(newHand);
            }
        } else {
            // If it does not contain a straight, then just its just a flush.
            newHand = fillHandFlush(hand, flushSuit);
            return "Flush\n" + handToString(newHand);
        }
    } else {
        // If hand does not have a flush.
        // If hand has a four of a kind. 
        int four = fourKind(hand);
        if (four != -1) {
            newHand = fillHand(hand, four, -1);
            return "Four of a Kind\n" + handToString(newHand);
        } 

        int triples = triple(hand);
        vector<int> pairs = pair(hand);
        // If hand has a full house.
        if (checkFullHouse(triples, pairs)) {
            int pairNo = -1;
            for (int i = 0; i < pairs.size(); i++) {
                if (pairs[i] != triples) {pairNo = pairs[i]; break;}
            }
            newHand = fillHand(hand, triples, pairNo);
            return "Full House\n" + handToString(newHand);
        }

        // If hand has a straight.
        int straightStartOther = straight(hand);
        if (straightStartOther != -1) {
            newHand = fillHandStraight(hand, straightStartOther);
            return "Straight\n" + handToString(newHand);
        }

        // If hand has a three of a kind.
        if (triples != -1) {
            newHand = fillHand(hand, triples, -1);
            return "Triples\n" + handToString(newHand);
        }

        // If hand has a two pair.
        if (pairs.size() >= 2) {
            newHand = fillHand(hand, hand[0].getRank(), hand[1].getRank());
            return "Two Pair\n" + handToString(newHand);
        }

        // If hand has a pair.
        if (pairs.size() == 1) {
            newHand = fillHand(hand, hand[0].getRank(), -1);
            return "Single Pair\n" + handToString(newHand);
        }

        // Otherwise we take the highest card.
        newHand = fillHand(hand, -1, -1);
        return "Highest Card\n" + handToString(newHand);
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
vector<Card> Hand::fillHand(vector<Card> hand, int rank1, int rank2) {
    vector<Card> newHand;
    
    // Inserts cards with first required rank.
    for (int i = 0; i < hand.size(); i++) {
        if (hand[i].getRank() == rank1) newHand.push_back(hand[i]);
    }

    // Inserts cards with second required rank.
    for (int i = 0; i < hand.size(); i++) {
        if (hand[i].getRank() == rank2) newHand.push_back(hand[i]);
    }

    // Fills out hand if hand is not full.
    for (int i = 0; i < hand.size(); i++) {
        if (newHand.size() < 5 && hand[i].getRank() != rank1 && hand[i].getRank() != rank2) {
            newHand.push_back(hand[i]);
        }
    }
    
    return newHand;
}

// Fills up a hand with a straight.
vector<Card> Hand::fillHandStraight(vector<Card> hand, int straightStart) {
    vector<Card> newHand;
    for (int i = straightStart; i < hand.size(); i++) {
        if (newHand.size() < 5) newHand.push_back(hand[i]);
    }
    return newHand;
}

// Fills up a hand with a straight flush.
vector<Card> Hand::fillHandStraightFlush(vector<Card> hand, int start, string suit) {
    vector<Card> newHand;
    for (int i = start; i < hand.size(); i++) {
        if (newHand.size() < 5 && !hand[i].getSuit().compare(suit)) newHand.push_back(hand[i]);
    }
    return newHand;
}
        
// Fills up a hand with a a flush.
vector<Card> Hand::fillHandFlush(vector<Card> hand, string suit) {
    vector<Card> newHand;
    for (int i = 0; i < hand.size(); i++) {
        if (newHand.size() < 5 && !hand[i].getSuit().compare(suit)) newHand.push_back(hand[i]);
    }
    return newHand;
}
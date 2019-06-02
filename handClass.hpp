#include <iostream>
#include <vector>
#include "cardClass.hpp"


class Hand {
    public:
        //Constructor
        Hand(vector<Card> hand);
        //Methods
        vector<Card> getHand(); //Returns hand.
        void printCards();      //Prints out cards.
        string bestHand();      //Returns the best hand.
        vector<Card> sortHand();//Returns a numerically sorted hand.
        string flush(vector<Card> hand); //Checks if there is a flush.
        int straight(vector<Card> hand); //Checks if there is a straight.
        bool compareHandRank(Card card1, Card card2); //Compares card ranks.
    private:
        vector<Card> _cards;
};

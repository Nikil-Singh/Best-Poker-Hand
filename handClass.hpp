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

    private:
        vector<Card> _cards;
};

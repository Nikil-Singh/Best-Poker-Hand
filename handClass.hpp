#include <iostream>
#include <vector>
#include "cardClass.hpp"


class Hand {
    public:
        //Constructor
        Hand(string cards);
        //Methods
        vector<Card> getCards();
        string bestHand();
        vector<Card> generateHand(string cards);
        void addCard(Card card);
    private:
        vector<Card> cards;
};

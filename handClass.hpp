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
        vector<Card> flushedHand(vector<Card> hand, string flushSuit); 
        string flush(vector<Card> hand); //Checks if there is a flush.
        int fourKind(vector<Card> hand); //Checks if there is a four of a kind.
        int straight(vector<Card> hand); //Checks if there is a straight.
        int triple(vector<Card> hand); //Checks if there is a triple.
        vector<int> pair(vector<Card> hand); //Checks if there is a pair.
        bool checkFullHouse(int triple, vector<int> pairs);
        string handToString(vector<Card> hand);
        vector<Card> fillHand(vector<Card> hand, int rank);
    private:
        vector<Card> _cards;
};

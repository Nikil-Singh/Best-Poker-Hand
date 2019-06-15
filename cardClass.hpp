#include <iostream>
using namespace std;

class Card {
    public:
        //Constructor for Card.
        Card(string newRank, string newSuit);

        //Methods for getting attributes.
        int getRank();   //Returns rank
        string getSuit();   //Returns suit
        string returnString(); //Returns card as a string.
        int convertRankToNum(string rank);
    private:
        int _rank;      //The rank of the card.
        string _suit;   //The suit of the card.
};

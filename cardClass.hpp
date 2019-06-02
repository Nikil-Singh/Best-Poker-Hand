#include <iostream>
using namespace std;

class Card {
    public:
        //Constructor for Card.
        Card(string newRank, string newSuit);

        //Methods for getting attributes.
        string getRank();   //Returns rank
        string getSuit();   //Returns suit
        string returnString(); //Returns card as a string.
    private:
        string _rank;      //The rank of the card.
        string _suit;   //The suit of the card.
};

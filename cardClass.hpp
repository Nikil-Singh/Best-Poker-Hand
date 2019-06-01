#include <iostream>
using namespace std;

class Card {
    public:
        //Constructor for Card.
        Card(int newRank, string newSuit);

        //Methods for getting attributes.
        int getRank();   //Returns rank
        string getSuit();//Returns suit

    private:
        int _rank;      //The rank of the card.
        string _suit;   //The suit of the card.
};

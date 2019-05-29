#include <iostream>
#include <cstring>
using namespace std;

class Card {
    public:

        Card(int newRank, string newSuit);

        int getRank();
        string getSuit();
    private:
        int _rank;
        string _suit;
};

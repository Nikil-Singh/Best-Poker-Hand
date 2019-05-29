#include "cardClass.hpp"

int main() {

    Card H6(6, "HEARTS");
    cout << H6.getRank() << " " << H6.getSuit() << endl;

    return 0;
}

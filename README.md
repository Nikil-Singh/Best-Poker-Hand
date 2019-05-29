# Best-Poker-Hand

This program takes in any valid poker hand ranging from 2 to 7 cards to give
back the best possible hand. The reasoning behind 2 to 7 cards is since the
player will receive 2 cards at the beginning, and the other 5 are from the
flop.

The suites will be denoted as C(Clubs), D(Diamonds), H(Hearts), S(Spades).
The ranks on the cards are ranged from 2, ..., 9, 10, J(Jack), Q(Queen),
K(King), and A(Ace) and valued in this order.

Duplicate cards are not excepted (i.e. 3H, 3H, AC) since in poker generally one
deck is used.

If more than 5 cards are entered, it will only return a hand of 5 based on the
rule a hand in poker can have no more than 5 cards.

Order of Best to Worst hand is:
    - Royal Flush     : A, K, Q, J, 10 all of the same suit.
    - Straight Flush  : Five cards in a sequence, all of the same suit.
    - Four of a Kind  : Four cards that all have the same rank.
    - Full House      : A three of a kind and a pair.
    - Flush           : Any five cards of the same suit, but not in a sequence.
    - Straight        : Five cards in a sequence, but no of the same suit.
    - Three of a Kind : Three cards, all of the same rank.
    - Two Pair        : Two different pairs.
    - Pair            : Two cards with the same rank.
    - High Card       : The highest card in hand when none of the above apply.

Input is given by rank of card followed by suite, then a single space between
each card.

Output returns the best hand in brackets, and the remainder cards following it
with 5 being the maximum number of cards being returned.

Examples:
1. Input  : 5C 2H 2C
   Output : Pair
            (2C 2H) 5C

2. Input  : 10H 9C 10D 10S 9D
   Output : Full House
            (10D 10H 10S 9C 9D)

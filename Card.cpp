#include "BlackJack.h"
#include <iostream>
using namespace std;



void Card::PrintCard() const {
    string cardName, suitName;

    switch (name) {
        case JACK: cardName = "Jack"; break;
        case QUEEN: cardName = "Queen"; break;
        case KING: cardName = "King"; break;
        case ACE: cardName = "Ace"; break;
        default: cardName = to_string(value); break;
    }

    switch (suit) {
        case CLUBS: suitName = "Clubs"; break;
        case DIAMONDS: suitName = "Diamonds"; break;
        case HEARTS: suitName = "Hearts"; break;
        case SPADES: suitName = "Spades"; break;
    }

    cout << cardName << " of " << suitName << endl;
}

Card::~Card(){
        //Nothing here
    }
#include "BlackJack.h"
#include <iostream>
using namespace std;



Deck::Deck(): deck(){

    deck.reserve(52);
    for(int s = Card::CLUBS; s<= Card::SPADES; ++s){
        for(int n = Card::ACE; n<=Card::KING; ++n){
            int cardValue = (n > 10) ? 10 : n;
            deck.push_back(new Card(static_cast<Card::CardNames>(n),
                                        static_cast<Card::Suits>(s), cardValue));

            
        }
    }
}


Deck::~Deck(){

    for (Card* card : deck){
        delete card;
    }
    deck.clear();
}


void Deck::PrintAll() const {
        for (const Card* card : deck) {
            card->PrintCard(); // This prints the full description using words for suits and ranks
        }
}

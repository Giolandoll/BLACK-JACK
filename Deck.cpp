#include "BlackJack.h"
#include <iostream>
#include <algorithm>
using namespace std;



Deck::Deck(): deck(){
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

void Deck::Shuffle(){
    random_shuffle(deck.begin(), deck.end());
}


// Card* Deck::TopCard(){
//     return deck.front();
// }


// void Deck::PopCard(){
//     deck.push_back(deck.front());
//     deck.erase(deck.begin());
// }

unique_ptr<Card> Deck::DealCard() {
    if (deck.empty()) {
        return nullptr; // Return null if no cards are left
    }
    Card* card = move(deck.back()); // Move the unique_ptr of the last card
    deck.pop_back();
    return unique_ptr<Card>(card); 
}

bool Deck::IsEmpty() const {
    return deck.empty();
}
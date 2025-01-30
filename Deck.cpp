#include "BlackJack.h"
#include <iostream>
#include <algorithm>
using namespace std;



Deck::Deck() {
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s) {
        for (int n = Card::ACE; n <= Card::KING; ++n) {
            int cardValue = (n > 10) ? 10 : n;
            deck.push_back(make_unique<Card>(static_cast<Card::CardNames>(n),
                                                static_cast<Card::Suits>(s), cardValue));
        }
    }
}

Deck::~Deck(){
    //Nothing here
}


void Deck::PrintAll() const {
        for (const auto& card : deck) {
            card->PrintCard(); // This prints the full description using words for suits and ranks
        }
}

void Deck::Shuffle(){
    // srand(999);
    random_shuffle(deck.begin(), deck.end());
}

unique_ptr<Card> Deck::DealCard() {
    if (deck.empty()) {
        return nullptr; //Return null if no cards are left
    }
    unique_ptr<Card> card = move(deck.back()); //Move the unique_ptr of the last card
    deck.pop_back();
    return card; 
}

bool Deck::IsEmpty() const {
    return deck.empty();
}

const std::vector<std::unique_ptr<Card>>& Deck::GetDeck() const {
    return deck;
}

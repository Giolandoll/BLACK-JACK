#include "BlackJack.h"
#include <iostream>
using namespace std;


Dealer::Dealer() : Player("Dealer") {}

//Dealer's automated play logic
void Dealer::Play(Deck& deck) {
    while (CalculateScore() < 17) {
        unique_ptr<Card> card = deck.DealCard();//Get a card from the deck
        if (card) {
            AddCard(move(card));//Add the card to the dealer's hand
        } else {
            cout << "No cards left in the deck!" << endl;
            break;
        }
    }

    PrintHand();
    if (CalculateScore() > 21) {
        cout << "Dealer busts!" << endl;
    } else {
        cout << "Dealer stands." << endl;
    }
}

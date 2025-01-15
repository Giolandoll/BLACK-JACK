#include <iostream>
#include "BlackJack.h"
#include <ctime>


int main(){

    srand(time(nullptr));
    Deck deck;
    deck.Shuffle();
    // deck.PrintAll();

    unique_ptr<Card> dealtCard = deck.DealCard();
    if (dealtCard) {
        dealtCard->PrintCard(); // Use the unique_ptr safely
    } else {
        cout << "No more cards in the deck!" << endl;
    }
    return 0;
}
#include <iostream>
#include "BlackJack.h"


int main(){

    Deck deck;
    deck.Shuffle();
    deck.PrintAll();

    cout << endl;
    Card * card = deck.TopCard();
    card->PrintCard();
    cout << endl;

    deck.PopCard();
    deck.PrintAll();
    return 0;
}
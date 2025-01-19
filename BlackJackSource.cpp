#include <iostream>
#include "BlackJack.h"
#include <ctime>
using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr))); // Seed random number generator for shuffling

    Deck deck;
    deck.Shuffle();

    Player player("John");
    Dealer dealer;

    // Deal initial cards to player and dealer
    player.AddCard(deck.DealCard());
    player.AddCard(deck.DealCard());
    dealer.AddCard(deck.DealCard());
    dealer.AddCard(deck.DealCard());

    // Print hands
    cout << player.GetName() << "'s hand:" << endl;
    player.PrintHand();

    cout << "Dealer's hand:" << endl;
    dealer.PrintHand(); // Assume the dealer hides one card initially

    // Player actions
    cout << "\n" << player.GetName() << "'s turn:" << endl;
    player.Hit(deck.DealCard()); // Example of a hit
    player.Stand();              // Example of standing

    // Dealer actions
    cout << "\nDealer's turn:" << endl;
    dealer.Play(deck);

    // Print final hands
    cout << "\nFinal hands:" << endl;
    cout << player.GetName() << "'s hand:" << endl;
    player.PrintHand();

    cout << "Dealer's hand:" << endl;
    dealer.PrintHand(); // Reveal all cards

    // Compare scores (assume functions like CalculateScore are implemented)
    int playerScore = player.CalculateScore();
    int dealerScore = dealer.CalculateScore();

    cout << "\nScores:" << endl;
    cout << player.GetName() << ": " << playerScore << endl;
    cout << "Dealer: " << dealerScore << endl;

    if (playerScore > 21) {
        cout << player.GetName() << " busted! Dealer wins." << endl;
    } else if (dealerScore > 21) {
        cout << "Dealer busted! " << player.GetName() << " wins." << endl;
    } else if (playerScore > dealerScore) {
        cout << player.GetName() << " wins!" << endl;
    } else if (playerScore < dealerScore) {
        cout << "Dealer wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }

    return 0;
}

// #include <iostream>
// #include "BlackJack.h"
// #include <ctime>
// using namespace std;

// int main() {
//     srand(static_cast<unsigned>(time(nullptr))); // Seed random number generator for shuffling

//     Deck deck;
//     deck.Shuffle();

//     Player player("John");
//     Dealer dealer;

//     // Deal initial cards to player and dealer
//     player.AddCard(deck.DealCard());
//     player.AddCard(deck.DealCard());
//     dealer.AddCard(deck.DealCard());
//     dealer.AddCard(deck.DealCard());

//     // Print hands
//     player.PrintHand();
//     dealer.PrintHand(); //Assume the dealer hides one card initially

//     // Player actions
//     cout << "\n" << player.GetName() << "'s turn:" << endl;
//     if(player.CalculateScore() < 21)
//         player.Hit(deck.DealCard()); // Example of a hit
//     else
//         player.Stand();              // Example of standing

//     player.PrintHand();

//     // Dealer actions
//     cout << "\nDealer's turn:" << endl;
//     dealer.Play(deck);

//     // Print final hands
//     cout << "\nFinal hands:" << endl;

//     player.PrintHand();
//     dealer.PrintHand(); 

//     // Compare scores (assume functions like CalculateScore are implemented)
//     int playerScore = player.CalculateScore();
//     int dealerScore = dealer.CalculateScore();

//     cout << "\nScores:" << endl;
//     cout << player.GetName() << ": " << playerScore << endl;
//     cout << "Dealer: " << dealerScore << endl;

//     if (playerScore > 21) {
//         cout << player.GetName() << " busted! Dealer wins." << endl;
//     } else if (dealerScore > 21) {
//         cout << "Dealer busted! " << player.GetName() << " wins." << endl;
//     } else if (playerScore > dealerScore) {
//         cout << player.GetName() << " wins!" << endl;
//     } else if (playerScore < dealerScore) {
//         cout << "Dealer wins!" << endl;
//     } else {
//         cout << "It's a tie!" << endl;
//     }

//     return 0;
// }


#include <iostream>
#include <string>
#include "BlackJack.h"
#include <vector>
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

    // Print initial hands
    cout << "\nInitial Hands:" << endl;
    player.PrintHand();
    cout << "Dealer shows: ";
    dealer.PrintHand(true); // Show only the first card of the dealer

    // Player's turn
    bool playerTurn = true;
    while (playerTurn) {
        cout << "\n" << player.GetName() << ", choose an action: (H)it, (S)tand, S(p)lit, (D)ouble Down: ";
        char choice;
        cin >> choice;

        switch (toupper(choice)) {
            case 'H': {
                // Hit
                player.Hit(deck.DealCard());
                player.PrintHand();
                if (player.CalculateScore() > 21) {
                    cout << "You busted!" << endl;
                    playerTurn = false;
                }
                break;
            }
            case 'S': {
                // Stand
                cout << player.GetName() << " stands." << endl;
                player.Stand();
                playerTurn = false;
                break;
            }
            case 'P': {
                // Split (for simplicity, only split if two cards have the same value)
                if(player.CanSplit()){
                    vector<unique_ptr<Card>> newHand;
                    player.Split(newHand);
                    player.AddCard(deck.DealCard()); // Deal one card to the first hand
                    newHand.push_back(deck.DealCard()); // Deal one card to the new hand
                    cout << "New hands after splitting:\n";
                    cout << "First Hand:\n";
                    player.PrintHand();
                    cout << "Second Hand:\n";
                    for (const auto& card : newHand) {
                        card->PrintCard();
                    }
                   
                }else{
                    cout << "You can't split these cards!" << endl;
                }
                
                break;
            }
            case 'D': {
                // Double Down (takes one card and stands immediately)
                if (player.GetHandSize() == 2) {
                    cout << "Doubling down!" << endl;
                    player.Hit(deck.DealCard());
                    player.PrintHand();
                    player.Stand();
                    playerTurn = false;
                } else {
                    cout << "You can only double down on your first two cards!" << endl;
                }
                break;
            }
            default:
                cout << "Invalid choice. Please choose again." << endl;
        }
    }

    // Dealer's turn
    cout << "\nDealer's turn:" << endl;
    dealer.Play(deck);

    // Print final hands
    cout << "\nFinal Hands:" << endl;
    player.PrintHand();
    dealer.PrintHand();

    // Compare scores
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

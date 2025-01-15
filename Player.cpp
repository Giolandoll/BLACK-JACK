#include "BlackJack.h"
#include <iostream>


using namespace std;


Player::Player(const string& name) : name(name){}

void Player::AddCard(unique_ptr<Card> card){
    hand.push_back(move(card));
}

int Player::CalculateScore() const {
    int score = 0;
    int aces = 0;

    for (const auto& card : hand) {
        int cardValue = card->GetValue(); // Assuming value holds numeric value
        score += cardValue;

        // Count aces for special handling
        if (card->GetName() == Card::ACE) {
            ++aces;
        }
    }

    // Handle aces: make one ace count as 11 if it doesn't cause bust
    while (aces > 0 && score <= 21) {
        score += 10; // Convert ace from 1 to 11
        --aces;
    }

    return score;
}

void Player::PrintHand() const {
    cout << name << "'s Hand:" << endl;
    for (const auto& card : hand) {
        card->PrintCard(); // Use the Card class's PrintCard() method
    }
    cout << "Score: " << CalculateScore() << endl;
}

const string& Player::GetName() const {
    return name;
}

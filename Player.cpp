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
        int cardValue = card->GetValue(); //Assuming value holds numeric value
        score += cardValue;

        //Count aces for special handling
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
        card->PrintCard(); //Use the Card class's PrintCard() method
    }
    cout << "Score: " << CalculateScore() << endl;
}

const string& Player::GetName() const {
    return name;
}


//Player chooses to "Hit"
void Player::Hit(unique_ptr<Card> card) {
    if (!standing) {
        AddCard(move(card));
    } else {
        cout << name << " has already chosen to stand." << endl;
    }
}

//Player chooses to "Stand"
void Player::Stand() {
    standing = true;
    cout << name << " has chosen to stand." << endl;
}

//Check if the player can "Split"
bool Player::CanSplit() const {
    return hand.size() == 2 && hand[0]->GetValue() == hand[1]->GetValue();
}

//Split the player's hand into two hands
void Player::Split(vector<unique_ptr<Card>>& newHand) {
    if (CanSplit()) {
        newHand.push_back(move(hand.back()));
        hand.pop_back();
        cout << name << " has split their hand." << endl;
    } else {
        cout << "Split is not allowed." << endl;
    }
}

//Player chooses to "Double Down"
void Player::DoubleDown(unique_ptr<Card> card) {
    if (hand.size() == 2) {
        AddCard(move(card));
        standing = true; //Player must stand after doubling down
        cout << name << " has doubled down." << endl;
    } else {
        cout << "Double down is only allowed on the first two cards." << endl;
    }
}

//Check if the player is standing
bool Player::IsStanding() const {
    return standing;
}
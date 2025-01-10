#include <iostream>
#include <array>
using namespace std;

// Enumeration for Suits
enum class Suits {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,
};

// Enumeration for Card Names
enum class CardNames {
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
};

// Card class
class Card {
private:
    CardNames name;
    Suits suit;
    int value;

public:
    // Constructor
    Card(CardNames n = CardNames::ACE, Suits s = Suits::CLUBS, int v = 1)
        : name(n), suit(s), value(v) {}

    // Print the card details
    void PrintCard() const {
        PrintValue();
        cout << " of ";
        PrintSuit();
        cout << endl;
    }

    // Print the card's value
    void PrintValue() const {
        if (name == CardNames::JACK) {
            cout << "jack";
        } else if (name == CardNames::QUEEN) {
            cout << "queen";
        } else if (name == CardNames::KING) {
            cout << "king";
        } else if (name == CardNames::ACE) {
            cout << "ace";
        } else {
            cout << value;
        }
    }

    // Print the card's suit
    void PrintSuit() const {
        if (suit == Suits::CLUBS) {
            cout << "clubs";
        } else if (suit == Suits::DIAMONDS) {
            cout << "diamonds";
        } else if (suit == Suits::HEARTS) {
            cout << "hearts";
        } else if (suit == Suits::SPADES) {
            cout << "spades";
        }
    }
};

// Deck class (manages a collection of cards)
class Deck {
private:
    array<Card, 52> arrCards; // Fixed-size array to store 52 cards

public:
    // Initialize the deck
    void SetupCards() {
        int index = 0;
        for (int suit = (int)Suits::CLUBS; suit <= (int)Suits::SPADES; ++suit) {
            for (int rank = (int)CardNames::ACE; rank <= (int)CardNames::KING; ++rank) {
                CardNames cardName = static_cast<CardNames>(rank);
                Suits cardSuit = static_cast<Suits>(suit);
                int cardValue = (rank > 10) ? 10 : rank; // JACK, QUEEN, KING -> 10
                arrCards[index++] = Card(cardName, cardSuit, cardValue);
            }
        }
    }

    // Print all cards in the deck
    void PrintAll() const {
        for (const auto& card : arrCards) {
            card.PrintCard();
        }
    }
};

// Main function
int main() {
    Deck deck;
    deck.SetupCards();

    cout << endl;

    deck.PrintAll();

    return 0;
}

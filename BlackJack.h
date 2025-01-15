#include <iostream>
#include <array>
#include <deque>
#include <vector>
#include <memory>

using namespace std;



// Card class
class Card {
private:
    int name;
    int suit;
    int value;

public:

    // Enumeration for Suits
    enum Suits {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES,
    };

    // Enumeration for Card Names
    enum CardNames {
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


    // Constructor
    Card(CardNames n = ACE, Suits s =CLUBS, int v = 1)
        : name(n), suit(s), value(v) {}

    int GetValue() const;// Get card value
    CardNames GetName() const;// Get card name
    Suits GetSuit() const;      

    
    virtual ~Card(); // Virtual destructor
    void PrintCard() const;    

    
};

// Deck class (manages a collection of cards)
class Deck {

private:
    deque<Card*> deck;

public:
    Deck();
    ~Deck();
    void Shuffle();
    void PrintAll() const;

    // Card* TopCard();//Takes the top card and shows it face
    // void  PopCard();//'Burns' the top card
    unique_ptr<Card> DealCard(); // Add this to deal a card
    bool IsEmpty() const;            // Check if the deck is empty

};


class Player{

private:
    string name;
    vector<unique_ptr<Card>> hand;

public:

    Player(const string& name);

    void AddCard(unique_ptr<Card> card);
    void PrintHand() const;
    const string &GetName() const;
    int CalculateScore() const;


};
using namespace std;
#include <iostream>


enum class Suits{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,
};


enum class CardNames{

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

//Card class 
class Card{

    protected: 
        CardNames name;
        Suits suit;
        int value;

    public: 

    Card(CardNames n = CardNames::ACE, Suits s = Suits::CLUBS, int v = 1) : name(n), suit(s), value(v) {}

        void PrintCard(){

            PrintValue();
            cout << " of ";
            PrintSuit();
            cout << endl;

        }

        void PrintValue(){

            if (name == CardNames::JACK){
                cout << "jack";
            }else if (name == CardNames::QUEEN){
                cout << "queen";
            }else if (name == CardNames::KING){
                cout << "king";
            }else if(name == CardNames::ACE){
                cout << "ace";
            }else{
                cout << value;
            }
        }

        void PrintSuit(){
            if (suit == Suits::CLUBS){
                cout << "clubs";
            }else if(suit == Suits::DIAMONDS){
                cout << "diamonds";
            }else if(suit == Suits::HEARTS){
                cout << "hearts";
            }else if(suit == Suits::SPADES){
                cout << "spades";
            }
        }
};

//Deck class which inherits from parent Card
class Deck : public Card{

    private: 
        Card arrCards[52];


    public:
        void SetupCards(){
            int index = 0;
            for (int cols = (int)Suits::CLUBS; cols <= (int)Suits::SPADES; cols++){
                for ( int row = (int)CardNames::ACE; row <= (int)CardNames::KING; row++){
                    CardNames c = static_cast<CardNames>(row);
                    Suits s = static_cast<Suits>(cols);
                    
                int cardValue = (row > 10) ? 10 : row; // JACK, QUEEN, KING -> 10
                    arrCards[index++] = Card(c, s, cardValue);
                    cout << (int)c << "of" << (int)s <<endl;
                }
            }
        }


        void PrintAll(){
            for (int cols = (int)Suits::CLUBS; cols <= (int)Suits::SPADES; cols++){
                for ( int row = (int)CardNames::ACE; row <= (int)CardNames::KING; row++){         
                    int index = (13*cols) + row -1;
                    arrCards[index].PrintCard();
                }
                cout << endl;
            }
        }

};



int main(){

    Deck deck;
    deck.SetupCards();

    cout << endl;

    deck.PrintAll();
}
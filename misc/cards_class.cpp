#include <iostream>

#define DECK_SIZE 52

using namespace std;

class Card {
    private:
        string cardFace;
        string cardSuit;

    public:
        // constructor
        Card(string cardFace="", string cardSuit="") {
            this->cardFace = cardFace;
            this->cardSuit = cardSuit;
        }

        // copy constructor
        Card(const Card &card) {
            this->cardFace = card.cardFace;
            this->cardSuit = card.cardSuit;
        }

        // access members
        string getCardFace() const {
            return cardFace;
        }
        string getCardSuit() const {
            return cardSuit;
        }

        // set members
        void setCardFace(string cardFace) {
            this->cardFace = cardFace;
        }
        void setCardSuit(string cardSuit) {
            this->cardSuit = cardSuit;
        }

        // print functions
        void printCard();
};

void Card::printCard() {
    cout << cardSuit << ":" << cardFace << endl;
}

class DeckOfCards {
    private:
        int currentCard;
    public:
        Card deck[DECK_SIZE];
        // default constructor
        DeckOfCards();

        // access functions
        int getDeckSize() const {
            return sizeof(deck)/sizeof(deck[0]);
        }

        // print deck of cards
        void printDeckOfCards();
        // Shuffle cards
        //void shuffleCards();

        // Deal a card
        //Card dealCard();
};

// Constructor for DeckOfCards
DeckOfCards::DeckOfCards() {

    // All cardFaces
    string faces[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    // All cardSuits
    string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    // inialize member variables
    currentCard = 0;

    Card * deck = new Card[DECK_SIZE];
    int k = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 13; j++) {
            deck[k] = Card(faces[j], suits[i]);
            k++;
        }
    }
}

void DeckOfCards::printDeckOfCards() {
    for(int i = 0; i < DECK_SIZE; i++) {
        //cout << deck[i].printCard();
        Card temp = deck[i];
        temp.printCard();
    }
}

int main() {
    Card card("a", "b");
    card.printCard();
    // this is the deck of cards we will use for the game
    DeckOfCards newDeck;
    cout << "Deck size " << newDeck.getDeckSize() << endl;

    newDeck.printDeckOfCards();

    return 0;
}

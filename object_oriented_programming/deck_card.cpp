#include <iostream>
#include <vector>

using namespace std;

string suits[4] = {"Hearts", "Diamonds", "Spades", "Clubs"};
string faces[12]={"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "Jack", "Queen", "King"};

class Card {

    private:
        bool available = true;

        int face;
        int suit;

        public:
            Card(int face, int suit) {
                this->face = face;
                this->suit = suit;
            }

            // Check if card is available to be given out to someone
            bool isAvailable() { return available; }

            void markUnavailable() { available = false; }
            void markAvailable() { available = true; }
};

class Deck {

    private:
        // all cards dealt or not
        vector<Card> deck;

        // marks first undealt card
        int dealtlndex = 0;

    public:
        Deck() {
            for(int i = 0; i < 13; i++) {
                for(int j = 0; j < 4; j++) {
                    Card card(i, j);
                    deck.push_back(card);
                }
            }
        }
        
        //void setDeckOfCards(ArrayList<T> deckOfCards) {
//            ???
//        }
//
//        void shuffle() { ... }
//
//        int remainingCards() {
//            return cards.size() - dealtlndex;
//        }
//
//        T[] dealHand(int number) { ... }
//
//        T dealCard() { ... }
};

//class Suit {
//    private:
//        Club (0), Diamond (1), Heart (2), Spade (3);
//        int value;
//
//        Suit(int v) {
//            value = v;
//        }
//
//    public:
//        int getValue() {
//            return value;
//        }
//
//        Suit getSuitFromValue(int value) {
//            ???
//        }
//};
//
//
//
//public class Hand <T extends Card> {
//    private:
//        ArrayList<T> cards = new ArrayList<T>();
//
//        int score() {
//            int score = 0;
//            for (T card : cards) {
//                score += card.value();
//            }
//            return score;
//        }
//
//    public:
//        void addCard(T card) {
//            cards.add(card);
//        }
//}

int main() {
    return 0;
}

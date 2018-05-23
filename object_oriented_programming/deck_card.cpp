class Suit {
	private:
		Club (0), Diamond (1), Heart (2), Spade (3);
		int value;

		Suit(int v) {
			value = v;
		}

	public:
		int getValue() {
			return value;
		}

		Suit getSuitFromValue(int value) {
			???
		}
};

class Deck <T extends Card> {
	private:
		ArrayList<T> cards;			// all cards, dealt or not
		int dealtlndex = 0;			// marks first undealt card

	public:
		void setDeckOfCards(ArrayList<T> deckOfCards) {
			???
		}

		void shuffle() { ... }

		int remainingCards() {
			return cards.size() - dealtlndex;
		}

		T[] dealHand(int number) { ... }

		T dealCard() { ... }
}

public abstract class Card {
	private:
		boolean available = true;

		/* 	number or face that's on card - 
			a number 2 through 10, or 11 * for Jack, 12 for Queen, 13 for King,
		 	or 1 for Ace
		 */
		
		int faceValue;
		Suit suit;

		public:
			Card(int c, Suit s) {
				faceValue = c;
				suit = s;
			}

			int value();
			Suit suit() { return suit; }

			/* Checks if the card is available to be given out to someone */
			boolean isAvailableQ { return available; }

			void markUnavailable() { available = false; }
			void markAvailable() { available = true; }
}

public class Hand <T extends Card> {
	private:
		ArrayList<T> cards = new ArrayList<T>();

		int score() {
			int score = 0;
			for (T card : cards) {
				score += card.value();
			}
			return score;
		}

	public:
		void addCard(T card) {
			cards.add(card);
		}
}
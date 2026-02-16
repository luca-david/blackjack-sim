#include <iostream>
#include "card-utils.h"
#include "card.h"

using namespace std;

string rankToString(Rank& rankOfCard) {
	switch (rankOfCard) {
	case TWO: return "Two";
	case THREE: return "Three";
	case FOUR: return "Four";
	case FIVE: return "Five";
	case SIX: return "Six";
	case SEVEN: return "Seven";
	case EIGHT: return "Eight";
	case NINE: return "Nine";
	case TEN: return "Ten";
	case JACK: return "Jack";
	case QUEEN: return "Queen";
	case KING: return "King";
	case ACE: return "Ace";
	default: return "Invalid";
	}
}

string symbolToString(Symbol& symbolOfCard) {
	if (symbolOfCard == HEARTS) {
		return "Hearts";
	}
	else if (symbolOfCard == DIAMONDS) {
		return "Diamonds";
	}
	else if (symbolOfCard == CLUBS) {
		return "Clubs";
	}
	else if (symbolOfCard == SPADES) {
		return "Spades";
	}
	else {
		return "Invalid";
	}
}

string cardToString(const Card& card) {
	Rank r = card.getRank();
	Symbol s = card.getSymbol();
	return rankToString(r) + " of " + symbolToString(s);
}

void displayCard(const Card& card) {
	cout << endl << "->" << cardToString(card);
}

int stringToNumber(const Card& card) {
	switch (card.getRank()) {
	case TWO: return 2;
	case THREE: return 3;
	case FOUR: return 4;
	case FIVE: return 5;
	case SIX: return 6;
	case SEVEN: return 7;
	case EIGHT: return 8;
	case NINE: return 9;
	case TEN: return 10;
	case JACK: return 10;
	case QUEEN: return 10;
	case KING: return 10;
	case ACE: return 11;
	default: return 0;
	}
}
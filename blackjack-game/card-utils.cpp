#include <iostream>
#include <fstream>
#include "card-utils.h"
#include "card.h"

using namespace std;

string rankToString(const Rank& rankOfCard) {
	//switch (rankOfCard) {
	//case TWO: return "Two";
	//case THREE: return "Three";
	//case FOUR: return "Four";
	//case FIVE: return "Five";
	//case SIX: return "Six";
	//case SEVEN: return "Seven";
	//case EIGHT: return "Eight";
	//case NINE: return "Nine";
	//case TEN: return "Ten";
	//case JACK: return "Jack";
	//case QUEEN: return "Queen";
	//case KING: return "King";
	//case ACE: return "Ace";
	//default: return "Invalid";
	//}
	switch (rankOfCard) {
	case ONE: return "1";
	case TWO: return "2";
	case THREE: return "3";
	case FOUR: return "4";
	case FIVE: return "5";
	case SIX: return "6";
	case SEVEN: return "7";
	case EIGHT: return "8";
	case NINE: return "9";
	case TEN: return "10";
	case JACK: return "J";
	case QUEEN: return "Q";
	case KING: return "K";
	case ACE: return "A";
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
	case ONE: return 1;
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

//void displayAsciiCard(const Card& card) { attemped to read from text file
//	ifstream file("ascii-cards.txt");
//	if (!file.is_open()) {
//		"Couldn't find file for ascii cards";
//	}
//	string inputText;
//
//	//get rank of the player's card as string
//	string currentRank = rankToString(card.getRank());
//
//	//get rank of player's card as int
//	int currentRankAsInt = stringToNumber(card);
//
//	//// go through the entire file
//	//while (getline(file, inputText)) {
//	//	// match rank of player's card to the rank in the text file
//	//	if (currentRank == "1") {
//	//		//cout << endl << " ___";
//	//		for (int i = 0; i < 4; i++) {
//	//			string matchedString;
//	//			getline(file, matchedString);
//	//			cout << endl << matchedString;
//	//		}
//	//		currentRank = "";
//	//	}
//	//}
//
//	//// go through the entire file
//	//while (getline(file, inputText)) {
//	//	// match the rank of player's card to the rank in the text file
//	//	for (int i = 0; i <= 10; i++) {
//	//		if (currentRankAsInt == i) {
//	//			cout << endl << " ___";
//	//			for (int j = 0; j < 4; j++) {
//	//				string matchedString;
//	//				getline(file, matchedString);
//	//				cout << endl << matchedString;
//	//			}
//	//		}
//	//	}
//	//}
//
//
//
//
//}

void displayAsciiCard(const Card& card) {
	string currentRank = rankToString(card.getRank());

	if (currentRank == "1") {
		cout << endl << " ___";
		cout << endl << "|1  |";
		cout << endl << "|   |";
		cout << endl << "|___|";
	}

	else if (currentRank == "2") {
		cout << endl << " ___";
		cout << endl << "|2  |";
		cout << endl << "|   |";
		cout << endl << "|___|";
	}

	else if (currentRank == "3") {
		cout << endl << " ___";
		cout << endl << "|3  |";
		cout << endl << "|   |";
		cout << endl << "|___|";
	}
	else if (currentRank == "4") {
		cout << endl << " ___";
		cout << endl << "|4  |";
		cout << endl << "|   |";
		cout << endl << "|___|";
	}
	else if (currentRank == "5") {
		cout << endl << " ___";
		cout << endl << "|5  |";
		cout << endl << "|   |";
		cout << endl << "|___|";
	}
	else if (currentRank == "6") {
		cout << endl << " ___";
		cout << endl << "|6  |";
		cout << endl << "|   |";
		cout << endl << "|___|";
	}
	else if (currentRank == "7") {
		cout << endl << " ___";
		cout << endl << "|7  |";
		cout << endl << "|   |";
		cout << endl << "|___|";
	}
	else if (currentRank == "8") {
		cout << endl << " ___";
		cout << endl << "|8  |";
		cout << endl << "|   |";
		cout << endl << "|___|";
	}
	else if (currentRank == "9") {
		cout << endl << " ___";
		cout << endl << "|9  |";
		cout << endl << "|   |";
		cout << endl << "|___|";
	}
	else if (currentRank == "10") {
		cout << endl << " ___";
		cout << endl << "|10 |";
		cout << endl << "|   |";
		cout << endl << "|___|";
	}
	else if (currentRank == "J") {
		cout << endl << " ___";
		cout << endl << "|J  |";
		cout << endl << "|   |";
		cout << endl << "|___|";
	}
	else if (currentRank == "Q") {
		cout << endl << " ___";
		cout << endl << "|Q  |";
		cout << endl << "|   |";
		cout << endl << "|___|";
	}
	else if (currentRank == "K") {
		cout << endl << " ___";
		cout << endl << "|K  |";
		cout << endl << "|   |";
		cout << endl << "|___|";
	}
	else if (currentRank == "A") {
		cout << endl << " ___";
		cout << endl << "|A  |";
		cout << endl << "|   |";
		cout << endl << "|___|";
	}
	else {
		cout << endl << "Unknown";
	}

}
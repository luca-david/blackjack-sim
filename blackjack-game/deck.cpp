#include <iostream>
#include "deck.h"
#include "card.h"
#include "card-utils.h"

Deck::Deck() {
	//first make an array of cards to store all cards created
	this->playingDeck = new Card[this->noOfCardsInDeck]; //calls default ctor 

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			this->playingDeck[this->count] = Card(static_cast<Rank>(j), static_cast<Symbol>(i)); //static_cast was needed here because we need to treat int j as Rank for it to access the elements of the enum
			this->count++;
		}
	}

	//make sure that the count of cards created is the same as the number of playing cards in a regular deck(52)
	if (this->count != this->noOfCardsInDeck) {
		std::cout << std::endl << "ERROR while creating the deck of cards!";
	}

	//shuffle the deck
	this->shuffleDeck();
}

Deck::~Deck() {
	delete[] this->playingDeck;
}

void Deck::displayDeck() {
	for (int i = 0; i < this->noOfCardsInDeck; i++) {
		displayCard(this->playingDeck[i]);
		std::cout << " [" << i << "]";
	}
	
	std::cout << std::endl << "///// number of cards created : " << this->count;
}


void Deck::shuffleDeck() {
	srand(time(0)); //use current time as a seed for random generator
	int countInstances = 0;
	for (int i = this->noOfCardsInDeck - 1; i >= 0; i--) { //starts from the bottom of the deck
		
		int randomNumber = rand() % (i + 1); // get a random number from 0 to i(including i)
		//std::cout << std::endl << "Card at position[" << i << "]: " << cardToString(this->playingDeck[i]);
		//std::cout << std::endl << "Random number generated: " << randomNumber;
		
		//swap position of card i with a random card from above(so it must be smaller than i)
		Card temp = this->playingDeck[i];
		this->playingDeck[i] = this->playingDeck[randomNumber]; 
		this->playingDeck[randomNumber] = temp;
	}
}

Card Deck::drawCard() {
	// return card from the top of the stack
	// (last index because it's more efficient than moving the elements to the left every time we call this function)
	this->noOfCardsInDeck--;

	Card cardToBeReturned = this->playingDeck[this->noOfCardsInDeck];
	
	if (this->noOfCardsInDeck <= 0) {
		std::cout << std::endl << "- Reached end of the card stack -";
	}

	return cardToBeReturned;

}
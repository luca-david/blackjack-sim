#pragma once
#include "card.h"

//a deck has 52 cards by default
class Deck {
	Card* playingDeck = nullptr;
	int noOfCardsInDeck = 52;
	int count = 0; //counts the cards
public:
	//creates a standard deck
	Deck();

	~Deck();
	
	void displayDeck();

	void shuffleDeck();

	Card drawCard();
};
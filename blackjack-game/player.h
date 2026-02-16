#pragma once
#include "card.h"
#include "deck.h"

class Player {
	Card* playerCards = nullptr;
	int* valuesForCards = nullptr;
	int runningTotal = 0;
	int noOfCards = 0;

public:
	void drawFromDeck(Deck& deck);
	int* getValuesForCards();
	int getRunningTotal();
	bool isUnder21();
	//void displayRunningTotal();
	void displayHand();
	void displayFirstCard();

	~Player();


};
#pragma once
#include "card.h"
#include "deck.h"

class Player {
	Card* playerCards = nullptr;
	int* valuesForCards = nullptr; // stores values of cards independently
	int runningTotal = 0;
	int noOfCards = 0;

public:
	void drawFromDeck(Deck& deck);
	int* getValuesForCards();
	void setValuesForCards();
	int getRunningTotal();
	void setRunningTotal();
	bool isUnder21();
	//void displayRunningTotal();
	void displayHand();
	void displayFirstCard();

	~Player();


};
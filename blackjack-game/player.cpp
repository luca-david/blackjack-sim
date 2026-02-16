#include "player.h"
#include "card-utils.h"
#include <iostream>

void Player::drawFromDeck(Deck& deck) {
	
	// save current cards in copy
	Card* copy = new Card[this->noOfCards];
	for (int i = 0; i < this->noOfCards; i++) {
		copy[i] = this->playerCards[i];
	}
	
	// avoid memory leak
	delete[] this->playerCards;
	
	// increment number of cards and create a bigger card array
	this->noOfCards++;
	this->playerCards = new Card[this->noOfCards];

	// load previous cards into the new array
	for (int i = 0; i < this->noOfCards - 1; i++) {
		//this->playerCards[i] = deck.drawCard();
		this->playerCards[i] = copy[i];
	}
	
	// draw a card at the new index
	this->playerCards[this->noOfCards - 1] = deck.drawCard();

	//std::cout << std::endl << "Player drew the following new card: ";
	//std::cout << cardToString(this->playerCards[this->noOfCards - 1]);


	//return deck.drawCard(); // returns card drawn from deck
}

int* Player::getValuesForCards() { // sets and returns the current values of the current cards
	delete[] this->valuesForCards;

	this->valuesForCards = new int[this->noOfCards];
	int* copy = new int[this->noOfCards]; // for deep copy

	for (int i = 0; i < this->noOfCards; i++) {
		copy[i] = stringToNumber(this->playerCards[i]);
	}

	return copy;
}

int Player::getRunningTotal() {
	for (int i = 0; i < this->noOfCards; i++) {
		this->runningTotal += this->getValuesForCards()[i];
	}

	return this->runningTotal;
}

bool Player::isUnder21() {
	if (this->runningTotal < 21) {
		return true;
	}
	else {
		return false;
	}
}

//void Player::displayRunningTotal() {
//	std::cout << std::endl << "Total: " << this->runningTotal;
//}

Player::~Player() {
	delete[] this->playerCards;
	delete[] this->valuesForCards;
}

void Player::displayHand() {
	std::cout << std::endl << "Current hand: ";
	for (int i = 0; i < this->noOfCards; i++) {
		displayCard(this->playerCards[i]);
	}
}

void Player::displayFirstCard() {
	std::cout << std::endl << "Dealer's first card: ";
	displayCard(this->playerCards[0]);
	std::cout << std::endl;
}

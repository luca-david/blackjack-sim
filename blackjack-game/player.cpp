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

	// modify values for cards array
	this->setValuesForCards();

	// modify running total
	this->setRunningTotal();

	//std::cout << std::endl << "Player drew the following new card: ";
	//std::cout << cardToString(this->playerCards[this->noOfCards - 1]);


	//return deck.drawCard(); // returns card drawn from deck
}

int* Player::getValuesForCards() { // returns the current values of the current cards

	int* copy = new int[this->noOfCards]; // for deep copy

	for (int i = 0; i < this->noOfCards; i++) {
		copy[i] = this->valuesForCards[i];
	}

	return copy;
}

void Player::setValuesForCards() { // value of each card gets stored in array
	delete[] this->valuesForCards;
	
	this->valuesForCards = new int[this->noOfCards];

	for (int i = 0; i < this->noOfCards; i++) {
		this->valuesForCards[i] = stringToNumber(this->playerCards[i]);
	}

}

int Player::getRunningTotal() {
	
	return this->runningTotal;
}

//void Player::setRunningTotal() { // sum up all numbers in valuesForCards
//	
//	for (int i = 0; i < this->noOfCards; i++) {
//		this->runningTotal += this->getValuesForCards()[i];
//	}
//}
void Player::setRunningTotal() { // sum up all numbers in valuesForCards
	
	this->runningTotal = 0;

	bool hasAce = false;
	int indexOfAce = 0;
	for (int i = 0; i < this->noOfCards; i++) {
		if (rankToString(this->playerCards[i].getRank()) == "Ace") {
			hasAce = true;
			indexOfAce = i;
		}
		this->runningTotal += this->valuesForCards[i];
	}

	// if player has an ace and has surpassed 21 the ace will have value 1

	if (hasAce == true && this->runningTotal > 21) {
		this->runningTotal = 0; // reset total 
		this->valuesForCards[indexOfAce] = 1; // modify value of ace 
		for (int i = 0; i < this->noOfCards; i++) {
			this->runningTotal += this->valuesForCards[i]; // recalculate total
		}
	}
}

bool Player::isUnder21() {
	if (this->runningTotal <= 21) {
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

#include <iostream>
#include "card.h"

using namespace std;

//Default Constructor
Card::Card() {
	//cout << endl << "Two of hearts card created(---built using default values---)";
}

//Parameterized constructor
Card::Card(Rank rankType, Symbol symbolType) {
	Card::setRank(rankType);
	Card::setSymbol(symbolType);
	//cout << endl << "Parameterized ctor used";
}

Card::~Card() {}

void Card::setRank(Rank rankType) {
	this->rank = rankType;
}

void Card::setSymbol(Symbol symbolType) {
	this->symbol = symbolType;
}

Rank Card::getRank() const {
	return this->rank;
}

Symbol Card::getSymbol() const {
	return this->symbol;
}

Card& Card::operator=(const Card& other) {
	rank = other.rank;
	symbol = other.symbol;
	return *this;
}
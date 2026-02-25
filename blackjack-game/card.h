#pragma once

enum Symbol {
	HEARTS = 0, 
	DIAMONDS, 
	CLUBS, 
	SPADES 
};

enum Rank {
	ONE = 0, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};

class Card {
	Rank rank = Rank::ONE;
	Symbol symbol = Symbol::HEARTS;
	

public:
	Card();
	Card(Rank rankType, Symbol symbolType);
	~Card();

	void setRank(Rank rankType);
	void setSymbol(Symbol symbolType);

	Rank getRank() const;
	Symbol getSymbol() const;

	//assignment operator
	Card& operator=(const Card& other);


};
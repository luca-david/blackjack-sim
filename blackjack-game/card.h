#pragma once

enum Symbol {
	HEARTS = 0, 
	DIAMONDS, 
	CLUBS, 
	SPADES 
};

enum Rank {
	TWO = 0, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};

class Card {
	Rank rank = Rank::TWO;
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
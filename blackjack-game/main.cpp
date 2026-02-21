#include <iostream>
#include <string>
#include <Windows.h>
#include "card.h"
#include "card-utils.h"
#include "deck.h"
#include "player.h"

using namespace std;

int main() {
		
	Deck d1;
	//d1.displayDeck();

	Player p1;
	Player dealer;

	bool gameover = false;
	char input;

	while (gameover != true) {
		// start of the game

		// give the player and dealer 2 cards
		p1.drawFromDeck(d1);
		p1.drawFromDeck(d1);

		// display the first card drawn by the dealer
		dealer.drawFromDeck(d1);
		dealer.drawFromDeck(d1);
		dealer.displayFirstCard();

		// let the player choose if they want to draw another card(input from kb)
		p1.displayHand();

		p1.setValuesForCards();
		p1.setRunningTotal();
		int runningTotal = p1.getRunningTotal();
		cout << endl << "+Your running total+   " << runningTotal;
		cout << endl << endl << "Controls: " << "    " << "H - hit" << "    " << "S - stand";
		cout << endl << "Your choice: ";
		cin >> input;

		if (input == 'h' || input == 'H') {
			p1.drawFromDeck(d1);
			
			p1.setValuesForCards(); 
			p1.setRunningTotal(); 
			
			p1.displayHand();

			runningTotal = p1.getRunningTotal();
			cout << endl << "+Your running total+   " << runningTotal;
		}
		else if (input == 's' || input == 'S') {
			cout << endl << "Standing";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
		}
		else {
			cout << endl << "Unknown command";
		}

		if (p1.isUnder21() == false) {
			cout << endl << "You lose!";
			cout << endl << "Reason: Went over the limit of 21";
			gameover = 1;
		}
		else if (dealer.isUnder21() == false) {
			cout << endl << "You win!";
			cout << endl << "Reason: Dealer went over the limit of 21";
			gameover = 1;
		}

		else if (p1.getRunningTotal() < dealer.getRunningTotal()) {
			cout << endl << "You lose!";
			cout << endl << "Reason: Dealer has a greater running total";
			gameover = 1;
		}

		else if (p1.getRunningTotal() > dealer.getRunningTotal()) {
			cout << endl << "You win!";
			cout << endl << "Reason: You have a higher running total than the dealer";
			gameover = 1;
		}

		else if (p1.getRunningTotal() == dealer.getRunningTotal()) {
			cout << endl << "It's a tie!";
			cout << endl << "Same running total between player and dealer";
			gameover = 1;
		}

		else {
			cout << endl << "Undefined condtion"; // VERIFY WIN CONDITIONS
		}

	}

	
	
	//cout << endl << "Value of each current card: ";		// VALUE FOR EACH CARD, INDEPENDENTLY
	//for (int i = 0; i < 3; i++) {
	//	cout << p1.getValuesForCards()[i] << " ";
	//}

	//cout << endl << "Current total of cards: " << p1.getRunningTotal(); // VALUE OF ALL CARDS, TOTAL
	

	//cout << endl << endl;
	//p1.displayHand();


	cout << endl;
	return 0;
}
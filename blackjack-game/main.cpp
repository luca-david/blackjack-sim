#include <iostream>
#include <string>
#include <Windows.h>
#include "card.h"
#include "card-utils.h"
#include "deck.h"
#include "player.h"

using namespace std;

int main() {
		
	//Deck d1;

	//Player p1;
	//Player dealer;

	bool gameover = false;
	char input = ' ';

	//fix game loop
	
	//while input != x
		//while gameover != true

	// start of the round
	while (input != 'n' || input != 'N') {
	
		// start of the game
		while (gameover != true) {

			Deck d1;

			Player p1;
			Player dealer;

			// give the player and dealer 2 cards
			p1.drawFromDeck(d1);
			p1.drawFromDeck(d1);

			// display the first card drawn by the dealer
			dealer.drawFromDeck(d1);
			dealer.drawFromDeck(d1);
			dealer.displayFirstCard();
			for (int i = 0; i < dealer.getNoOfCards() - 1; i++) {
				displayAsciiCard(dealer.getCards()[i]);
			}

			// let the player choose if they want to draw another card(input from kb)
			p1.displayHand();
			for (int i = 0; i < p1.getNoOfCards(); i++) {
				displayAsciiCard(p1.getCards()[i]);
			}


			p1.setValuesForCards();
			p1.setRunningTotal();
			int runningTotal = p1.getRunningTotal();
			cout << endl << endl << ">>>  Your running total: " << runningTotal << "  <<<";
			cout << endl << endl << "Controls: " << "    " << "H - hit" << "    " << "S - stand";
			cout << endl << "Your choice: ";
			cin >> input;

			if (input == 'h' || input == 'H') {
				cin.get(); // get rid of \n character
				
				p1.drawFromDeck(d1);

				p1.setValuesForCards();
				p1.setRunningTotal();

				p1.displayHand();
				for (int i = 0; i < p1.getNoOfCards(); i++) {
					displayAsciiCard(p1.getCards()[i]);
				}

				runningTotal = p1.getRunningTotal();
				cout << endl << endl << ">>>  Your running total: " << runningTotal << "  <<<";
			}
			else if (input == 's' || input == 'S') {
				cin.get(); // get rid of \n character

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
				int dealerTotal = dealer.getRunningTotal();
				cout << endl << endl << "You lose!";
				cout << endl << "Reason: Went over the limit of 21";
				cout << endl << "Dealer's total: (" << dealerTotal << ")";
				gameover = true;
			}
			else if (dealer.isUnder21() == false) {
				int dealerTotal = dealer.getRunningTotal();
				cout << endl << endl << "You win!";
				cout << endl << "Reason: Dealer went over the limit of 21(" << dealerTotal << ")";
				gameover = true;
			}

			else if (p1.getRunningTotal() < dealer.getRunningTotal()) {
				int dealerTotal = dealer.getRunningTotal();
				cout << endl << endl << "You lose!";
				cout << endl << "Reason: Dealer has a greater running total(" << dealerTotal << ")";
				gameover = true;
			}

			else if (p1.getRunningTotal() > dealer.getRunningTotal()) {
				int dealerTotal = dealer.getRunningTotal();
				cout << endl << endl << "You win!";
				cout << endl << "Reason: You have a higher running total than the dealer";
				cout << endl << "Dealer's total: (" << dealerTotal << ")";
				gameover = true;
			}

			else if (p1.getRunningTotal() == dealer.getRunningTotal()) {
				cout << endl << endl << "It's a tie!";
				cout << endl << "Same running total between player and dealer";
				gameover = true;
			}

			else {
				cout << endl << "Undefined condtion"; 
			}
		}

		cout << endl;
		cout << endl << "--------------------------------------" << endl << "Want to play again? Y/N   ->     ";
		cin >> input;

		if (input == 'Y' || input == 'y') {
			cin.get();
			gameover = false; // reset the game loop
			system("cls");
		}
		else if (input == 'N' || input == 'n') {
			cin.get();
			cout << endl << "See you later!";
		}
		else {
			cin.get();
			cout << endl << "Invalid input, but the game will close";
		}

	}
	
	
	//cout << endl << "Value of each current card: ";		// VALUE FOR EACH CARD, INDEPENDENTLY
	//for (int i = 0; i < 3; i++) {
	//	cout << p1.getValuesForCards()[i] << " ";
	//}

	//cout << endl << "Current total of cards: " << p1.getRunningTotal(); // VALUE OF ALL CARDS, TOTAL
	

	//cout << endl << endl;
	//p1.displayHand();

	
	//cout << endl << endl << "Press ENTER to exit.";
	//cin.get();

	cout << endl;
	return 0;
}
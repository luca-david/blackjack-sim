#pragma once
#include <string>
#include "card.h"

std::string rankToString(const Rank& rankOfCard);
std::string symbolToString(Symbol& symbolOfCard);
std::string cardToString(const Card& card);
int stringToNumber(const Card& card); // converts the string of the card to its value
void displayCard(const Card& card);

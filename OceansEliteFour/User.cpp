//
//  User.cpp
//  CardsSimulator
//
//  Created by Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath on 12/11/15.
//  Copyright (c) 2015 Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath. All rights reserved.
//

#include <stdio.h>
#include "User.h"
#include <iostream>
#include <string>

//constructor
User::User(){
    totalMoney = 500;
    betAmount = 0;
    cardTotal = 0;
}

//copy constructor
User::User(User& userToCopy){
    totalMoney=userToCopy.getTotalMoney();
    betAmount=userToCopy.betAmount;
    cardTotal=userToCopy.cardTotal;
}

//destructor
User::~User(){
    emptyHand();
}

//prints out in string form the card objects contained in the hand list
void User::displayHand() {
	std::cout << "Your hand contains:\n";
	Node* root = hand.getTopNodePointer();

	while (root != nullptr) {
		Card current = root->getData();
		std::cout << current.toString() << std::endl;
		root = root->getNext();
	}

	std::cout << "\n";
}

//adds a Card object to the user's hand
void User::addCard(Card newCard) {
	hand.add(newCard);
}

//returns the total value of the cards in the hand list
int User::getCardTotal() {
	return cardTotal;
}

//updates the total value of the cards in the hand list
void User::updateCardTotal() {
	cardTotal = 0;
	Node* root = hand.getTopNodePointer();
	Card rootCard = root->getData();
	while (root != nullptr) {

		//if the card is a Jack, Queen, or King
		if (rootCard.getFaceValue() == 11 || rootCard.getFaceValue() == 12 || rootCard.getFaceValue() == 13) {
			//its value is 10
			cardTotal += 10;
		}

		//if the card is an Ace
		else if (rootCard.getFaceValue() == 1) {

			//its value is 11 (according to our house rules)
			cardTotal += 11;
		}

		//if the card is a 2-10
		else {
			cardTotal += rootCard.getFaceValue();
		}
		root = root->getNext();
		if (root != nullptr) {
			rootCard = root->getData();
		}
	}
}

//takes in a deck object by reference
//shows the user their cards
//gives the user the opportunity to check the probability of drawing a specific card value
//lets the user make and increase bets
//lets the user decide whether to hit (draw another card) or not
//announces whether the user hit 21 or went over 21 (if either happens)
void User::takeTurn(Deck& myDeck) {
    bool willTakeTurn = true;
    while (willTakeTurn) {
        std::cout << "\n";
        displayHand();
        updateCardTotal();
        if (cardTotal == 21) {
            std::cout << "You hit 21! \n \n";
            willTakeTurn = false;
        }
        else if (cardTotal > 21) {
            std::cout << "You lost by going over 21.  \n \n";
            willTakeTurn = false;
        }
        
        else {
			//allows the user to check the probability of a card
            std::cout << "Do you want to check the probability of a card? (yes/no) \n";
            std::string willCheck = "";
            std::cin >> willCheck;
            while(willCheck != "no" && willCheck != "NO" && willCheck != "No" && willCheck != "yes" && willCheck != "YES" && willCheck != "Yes"){
                std::cout<<"Please enter 'yes' or 'no.' "<<std::endl;
                std::cin >> willCheck;
            }
			if (willCheck == "yes" || willCheck == "YES" || willCheck == "Yes") {
				std::cout << "What card number would you like to look for? \n";
				std::string faceValue = "";
				//takes in a string from user
				std::cin >> faceValue;

				int faceInt;

				//converts a requested face value to a face value as recognized by the Card object
				if (faceValue == "Ace" || faceValue == "ace") {
					faceInt = 1;
				}
				else if (faceValue == "Jack" || faceValue == "jack") {
					faceInt = 11;
				}
				else if (faceValue == "Queen" || faceValue == "queen") {
					faceInt = 12;
				}
				else if (faceValue == "King" || faceValue == "king") {
					faceInt = 13;
				}
				else {

					//there are more efficient ways to do this, but this was guaranteed to work
					if (faceValue == "2"|| faceValue == "3" || faceValue == "4" || faceValue == "5" || faceValue == "6" || faceValue == "7" || faceValue == "8" || faceValue == "9" || faceValue == "10") {
						faceInt = std::stoi(faceValue);
					}
					
					//if the user does not enter a valid input
					else {
						std::cout << "Please enter a card value from 2 - 10 or a face card." << std::endl;
						takeTurn(myDeck);
					}
                }
                
                double probability = checkProbability(faceInt, myDeck);
                
                std::cout << "The probability of getting a "<<faceValue<<" is " << probability*100 << "%" << std::endl;
            }
            
			//give the user the opportunity to increase their bet
            makeBet();
            
			//lets the user decide whether or not to draw another card
            std::cout << "Do you want to hit? (yes/no) \n";
            std::string willHit = "";
            std::cin >> willHit;
            while(willHit != "no" && willHit != "NO" && willHit != "yes" && willHit != "YES"){
                std::cout<<"Please enter 'yes' or 'no.' "<<std::endl;
                std::cin >> willHit;
            }

			//if the user decides to draw another card
            if (willHit == "yes" || willHit == "Yes") {

                //grabs a new card from the deck via the draw function
                Card newCard = myDeck.draw();

                //appends this new card to the user's hand
				hand.add(newCard);

            }
            else {
                willTakeTurn = false;
            }
        }
    } 
}

//removes all of the card objects from the hand list
void User::emptyHand() {
	while (hand.size() > 0) {
		hand.remove(0);
	}
}

//returns the percentage chance of drawing a Card with the passed value
double User::checkProbability(int faceValue, Deck& myDeck) {
    int numDesiredCards = 0;
    
	//finds the number of Card objects with the requested face value in the deck
    for (int i = 0; i < myDeck.getNumCards(); i++) {
        if ((myDeck.getArr()[i]).getFaceValue() == faceValue) {
            numDesiredCards++;
        }
    }

	//divides that number by the number of Card objects remaining in the deck
    double probability = (double)numDesiredCards / (double)myDeck.getNumCards();

    return probability;
    
}

//lets the user make a bet (or add to their established bet during a round)
void User::makeBet(){
    std::cout << "How much would you like to bet?" <<std::endl;
    std::cout << "Money Available: $" << totalMoney <<std::endl;
    int bet;
	startLoop:
	while (true) {
		std::cin >> bet;

		//if the user enters a non-integer
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please enter a number: " << std::endl;
			goto startLoop;
		}

		//if the user tries to bet more money than theyhave
		if (bet >= 0 && bet <= totalMoney) {
			break;
		}

		std::cout << "Invalid bet try again" << std::endl;
	}
    betAmount+=bet;
    std::cout << "\nYou just bet: $" <<bet<<std::endl;
    std::cout << "Total hand bet: $" <<betAmount<<std::endl;
    totalMoney-=bet;
}

//resets the amount currently being bet
void User::emptyBet(){
    betAmount=0;
}

//return the total amount of money the user currently has
int User::getTotalMoney() {
	return totalMoney;
}

//increases the user's money by twice the amount they bet
void User::win(){
    int winnings = betAmount*2;
    totalMoney+=winnings;
}

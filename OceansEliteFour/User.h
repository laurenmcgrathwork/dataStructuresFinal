//
//  User.h
//  CardsSimulator
//
//  Created by Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath on 12/11/15.
//  Copyright (c) 2015 Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath. All rights reserved.
//

#ifndef Term_Project_User_h
#define Term_Project_User_h

#include <stdio.h>
#include "Deck.h"
#include "PlayerADT.h"
#include <list>
#include "LinkedList.h"

class User : public PlayerADT {
private:
	
	int betAmount;
	int totalMoney;
    int cardTotal;
	LinkedList hand;

public:
 
    //constructor
    User();

	//copy constructor
    User(User& userToCopy);

	//destructor
    ~User();

	//prints out in string form the card objects contained in the hand list
	void displayHand();

	//adds a Card object to the user's hand
	void addCard(Card newCard);

	//returns the total value of the cards in the hand list
    int getCardTotal();
    
	//updates the total value of the cards in the hand list
    void updateCardTotal();
    
	//takes in a deck object by reference
	//shows the user their cards
	//gives the user the opportunity to check the probability of drawing a specific card value
	//lets the user make and increase bets
	//lets the user decide whether to hit (draw another card) or not
	//announces whether the user hit 21 or went over 21 (if either happens)
    void takeTurn(Deck& myDeck);

	//removes all of the card objects from the hand list
	void emptyHand();

	//returns the percentage chance of drawing a Card with the passed value
    double checkProbability(int faceValue, Deck& myDeck);
    
	//lets the user make a bet (or add to their established bet during a round)
    void makeBet();
    
	//resets the amount currently being bet
    void emptyBet();
    
	//return the total amount of money the user currently has
	int getTotalMoney();
    
	//increases the user's money by twice the amount they bet
    void win();
    
};
#endif
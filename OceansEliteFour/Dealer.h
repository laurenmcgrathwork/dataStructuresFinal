//
//  Dealer.h
//  CardsSimulator
//
//  Created by Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath on 12/11/15.
//  Copyright (c) 2015 Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath. All rights reserved.
//

#ifndef Term_Project_Dealer_h
#define Term_Project_Dealer_h

#include <stdio.h>
#include "PlayerADT.h"
#include "Deck.h"
#include <list>
#include "LinkedList.h"

class Dealer : public PlayerADT {
private:
	
	bool willPlay;
    int cardTotal;
	LinkedList hand;

public:

	//constructor
    Dealer();

	//copy constructor
    Dealer(Dealer &dealerToCopy);

	//dealer
    ~Dealer();
    
	//prints out in string form the card objects contained in the hand list
    void displayHand();

	//add a new card to the hand list
	void addCard(Card newCard);
    
	//returns the total value of the cards in the hand list
	int getCardTotal();

	//updates the total value of the cards in the hand list
    void updateCardTotal();

	//takes in a deck object by reference
	//automatically has the dealer draw or not draw cards based on cardTotal
	//announces when the dealer hits and whether the dealer hit 21 or went over
	void takeTurn(Deck& d);
    
	//removes all of the card objects from the hand list
    void emptyHand();
	
};
#endif

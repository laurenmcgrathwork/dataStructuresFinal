//
//  PlayerADT.h
//  CardsSimulator
//
//  Created by Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath on 12/11/15.
//  Copyright (c) 2015 Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath. All rights reserved.
//

#ifndef Term_Project_Player_h
#define Term_Project_Player_h

#include <stdio.h>
#include "Deck.h"
#include <list>

class PlayerADT {
private:
	

public:

	//prints out in string form the card objects contained in the hand list
	virtual void displayHand() = 0;

	//adds a Card object to a player's hand
	virtual void addCard(Card newCard) = 0;

	//returns the total value of the cards in the hand list
	virtual int getCardTotal() = 0;

	//update the total value of the cards in the hand list
	virtual void updateCardTotal() = 0;
	
	//total value of cards in hand is checked
	//more cards may or may not be added to the hand based on that total or a user's choice
	//options such as checking probability or making bets may be made available
	//card total is checked, and there is an announcement made if it is 21 exactly or over 21
	virtual void takeTurn(Deck& d) = 0;

	//removes all of the card objects from the hand list
	virtual void emptyHand() = 0;

};
#endif
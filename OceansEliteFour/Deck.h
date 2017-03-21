//
//  Deck.h
//  CardsSimulator
//
//  Created by Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath on 12/11/15.
//  Copyright (c) 2015 Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath. All rights reserved.
//

#ifndef __CardsSimulator__Deck__
#define __CardsSimulator__Deck__

#include <stdio.h>
#include "Card.h"

class PopFromEmptyException : std::exception {};

class Deck {
private:

    int numCards;
    Card* arr;
    
	/*pushes a specific card into the deck
	does not currently exist, but could be added functionality later.
	in private for security purposes, but could be moved to public depending on how it will be implemented and used*/
	//void push(Card c);
    
    
public:
	
	//constructor
    Deck();

	//copy constructor
    Deck(Deck &deckToCopy);

	//destructor
	~Deck();
    
	//returns the number of Card objects currently in the Deck object
	int getNumCards();

	Card* getArr();

	//randomizes the order of the Card objects within the Deck object
	void shuffle();

	//prints the contents of the Deck array as a string
	void toString();

	//removes a Card object from the Deck object and returns that Card object
    Card draw();

	//takes an array and copies it and creates a new array of the same number
	//this new array must be deleted by whatever calls this function.
	Card* copyArrayPop(const Card* arrayToCopy, const int size);
    
};
#endif /* defined(__CardsSimulator__Deck__) */

//
//  Card.h
//  CardsSimulator
//
//  Created by Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath on 12/11/15.
//  Copyright (c) 2015 Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath. All rights reserved.
//

#ifndef __CardsSimulator__Card__
#define __CardsSimulator__Card__

#include <stdio.h>
#include <string>

class Card {
private:
    std::string suit;
    int faceVal;
    
public:

	//constructor
    Card();

	//copy constructor
    Card(std::string suit, int faceVal);

	//gets the face value of a card
	int getFaceValue();

	//prints the values of a Card object in string form
    std::string toString();

};

#endif /* defined(__CardsSimulator__Card__) */

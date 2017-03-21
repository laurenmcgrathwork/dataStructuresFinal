//
//  Game.h
//  CardsSimulator
//
//  Created by Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath on 12/11/15.
//  Copyright (c) 2015 Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath. All rights reserved.
//

#ifndef Term_Project_Game_h
#define Term_Project_Game_h

#include <stdio.h>
#include "Deck.h"
#include <iostream>
#include "playerADT.h"
#include "User.h"
#include "Dealer.h"
#include "HighestScore.h"

class Game{
private:
	Deck* gameDeck;
    Dealer* gameDealer;
    User* gameUser;

	//adds two Card objects to the hands of both the User and the Dealer
    void deal();

	HighestScore* gameHighScore;
    
public:
	
	//constructor
	Game();

	//copy constructor
	Game(Game& gameToCopy);

	//destructor
    ~Game();
    
	//creates and runs an instance of a Blackjack game
	//creates Deck, Dealer, and User objects which are deleted within the function
    void play();
};
#endif
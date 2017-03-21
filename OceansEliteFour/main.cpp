//
//  main.cpp
//  CardsSimulator
//
//  Created by Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath on 12/11/15.
//  Copyright (c) 2015 Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath. All rights reserved.
//

#include <iostream>
#include "Deck.h"
#include "Game.h"
#include <time.h>
#include "Highestscore.h"


int main(int argc, const char * argv[]) {
    // insert code here...
	//Highestscore score;
    
    srand (time(NULL));
    
    Game* myGame = new Game;
    
    myGame->play();
    
	delete myGame;
}

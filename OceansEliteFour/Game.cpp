//
//  Game.cpp
//  CardsSimulator
//
//  Created by Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath on 12/11/15.
//  Copyright (c) 2015 Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath. All rights reserved.
//

#include <stdio.h>
#include "Game.h"
#include <sstream>
#include <fstream>
#include "LinkedList.h"

//constructor
Game::Game(){
    //Don't need to make these 3 here because we create them and destruct them at the start and end of each hand (round)
    //gameDeck = new Deck();
    //gameDealer = new Dealer();
	//gameUser = new User();
	gameHighScore = new HighestScore();
}

//copy constructor
Game::Game(Game& gameToCopy){
    gameDeck=gameToCopy.gameDeck;
    gameDealer=gameToCopy.gameDealer;
    gameUser=gameToCopy.gameUser;
}

//destructor
Game::~Game(){
    
    //The 3 don't need to be deleted here because they get deleted at the end of every round already
    //We left them to show our reasoning as to why they are not included
    //delete gameDealer;
    //delete gameUser;
    //delete gameDeck;
    
    delete gameHighScore;
}

//creates and runs an instance of a Blackjack game
void Game::play(){

    //plays the game
    bool go = true;

	//prints the house rules
    std::cout << "Welcome to Ocean's 4 Blackjack \n----------------------------- \nHouse Rules:\n - All ACE cards count for 11\n - Bets double on win always\n - Tie always goes to the Dealer\n\nWould you like to print out the general rules for the game?(yes/no)";
    
    std::string seeRules = "";
    std::cin >> seeRules;
    while(seeRules != "no" && seeRules != "NO" && seeRules != "No" && seeRules != "yes" && seeRules != "YES"&& seeRules != "Yes"){
        std::cout<<"Please enter 'yes' or 'no.' "<<std::endl;
        std::cin >> seeRules;
    }

	//displays the rules of blackjack (as applicable here) if the user chooses to view them
    if (seeRules == "yes" || seeRules == "YES" || seeRules == "Yes") {
        std::cout << "The goal of the game is to get as close to 21 points as possible without going over.\nSuit does not matter.\nThe value of each card from 2-10 is its face value.  Jack, Queen, and King are each worth 10.\nAces are worth 11.\n\nWhen the game begins, you will make a bet, and then you and the dealer will each be dealt two cards.\nYou may increase your bet based on the cards you see, and you can check the probability of finding a specific card in the deck.\n\nAfter betting, you may hit (draw another card) or stay (refrain from drawing).\nIf you stay, the dealer takes their turn.\nIf you go over 21 points, you automatically lose regardless of what happens with the dealer.\nIf both you and the dealer are under 21 points at the end of a round, the player with the higher total wins the round.\nA tie goes to the dealer.\nIf the dealer busts (goes over 21) and you did not, you win.\nIf you win, you receive twice what you bet.\nEach game has three rounds played from the same deck without reshuffling.\nAt the end of each game, your score will be checked against the high score list, and if you are in the top 10, your score will be added!\n";
    }
    
    while (go) {
        std::cout <<"\n\n";
        //Used to create a new game state
        gameDeck = new Deck();
        gameDealer = new Dealer();
        gameUser = new User();
        gameDeck->shuffle();
        
        //variables for while loop
        int handLimit = 3;
        int handNum = 0;
        
        //an entire round of blackjack occurs here
        while (handNum < handLimit) {
            bool win = false;
            std::cout << "Round: " << handNum+1 << "\n-----------\n";
			//initializes the betting at 0
            gameUser->emptyBet();

			//allows the user to make a bet
            gameUser->makeBet();
            
			//deals two cards each to the dealer and user
            deal();
			
			//updates the dealer's card total, for immediate checking
            gameDealer->updateCardTotal();
            
			//as long as the dealer is not dealt exactly 21 off the bat (which is an instant-lose condition for the user)
            if (gameDealer->getCardTotal()!=21) {
                
				//the user takes their turn
                gameUser->takeTurn(*gameDeck);

				//the dealer takes their turn
                gameDealer->takeTurn(*gameDeck);

            }
            
            int userScore = gameUser->getCardTotal();
            int dealerScore = gameDealer->getCardTotal();
            
			//makes announcements based on card totals

			//if the dealer's card total is exactly 21
            if (dealerScore == 21) {
                std::cout << "Dealer hit 21. You lose." <<std::endl;
            }

			//if the user's card total and the dealer's card total are equivalent
			else if (userScore == dealerScore){
                std::cout << "Tie hands. You lose." <<std::endl;
            }

			//if the user's card total is 21, and the dealer's is not
			else if (userScore == 21){
                win=true;
                std::cout << "21! You win!" <<std::endl;
            }

			//if the dealer busts (goes over 21) and the user does not
			else if (dealerScore >21 && userScore < 21){
                win=true;
                std::cout << "You win!" <<std::endl;
            }

			//if the user's card total is over 21
			else if (userScore > 21){
                std::cout << "You bust. You lose." <<std::endl;
            }

			//if both scores are under 22 and the user's score is greater than the dealer's score
			else if (userScore > dealerScore && dealerScore < 22){
                win=true;
                std::cout << "You win!" <<std::endl;
            }

			//if none of the above conditions are true
			else {std::cout << "You lose." <<std::endl;}
            
			//if the user wins, give them they money they won according to their bets
            if (win == true) {
				gameUser->win();
			}
            //empty the dealer's and user's hands for a new round
            gameUser->emptyHand();
            gameDealer->emptyHand();

			//prepares for moving on to the next round
            handNum++;
        }
        
        //displays the user's score and asks for their name to insert into the score chart
        std::cout << "Your score: " << gameUser->getTotalMoney() <<std::endl << "Enter Your Name: ";
        std::string name;
        std::cin >> name;

        if (name != ""){
            //In order to save scores we need to give a name and score of the player that just played
            gameHighScore->saveScores(name, gameUser->getTotalMoney());
        }
        
        //asks if the user wants to see the high scores chart
        std::cout << "Enter (y) to view high scores." << std::endl;
        std::string viewScores;
        std::cin >> viewScores;

        if (viewScores == "y" || viewScores == "Y") {
            gameHighScore->printScores();
        }
        
        //asks if they want to play another game of blackjack
        std::cout << "Enter (y) to play again, otherwise enter anything else to quit." << std::endl;
        std::string playAgain;
        std::cin >> playAgain;

        if (playAgain == "y" || playAgain == "Y") {
            go = true;
        }

		else {
            go = false;
        }

		//cleans up the memory allocated when creating objects in this instance of the game
		delete gameDealer;
		delete gameUser;
		delete gameDeck;
    }
    
    //prints scoreboard and closes
    gameHighScore->printScores();
    std::cout<<"Thank you for playing!"<<std::endl;
    return;
}

//adds two Card objects to the hands of both the User and the Dealer
void Game::deal(){
    Card draw1 = gameDeck->draw();
    Card draw2 = gameDeck->draw();
    Card draw3 = gameDeck->draw();
    Card draw4 = gameDeck->draw();
    
	//deals two cards to the user
	gameUser->addCard(draw1);
	gameUser->addCard(draw2);
    
	//deals two cards to the dealer
	gameDealer->addCard(draw3);
	gameDealer->addCard(draw4);
    
    //prints out the hand of the dealer
	gameDealer->displayHand();
    std::cout << std::endl;
}
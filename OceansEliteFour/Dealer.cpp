//
//  Dealer.cpp
//  CardsSimulator
//
//  Created by Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath on 12/11/15.
//  Copyright (c) 2015 Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath. All rights reserved.
//

#include <stdio.h>
#include "Dealer.h"
#include <string>
#include <iostream>

//constructor
Dealer::Dealer(){
    willPlay = true;
    cardTotal=0;
}

//copy constructor
Dealer::Dealer(Dealer &dealerToCopy){
    willPlay=dealerToCopy.willPlay;
    cardTotal=dealerToCopy.cardTotal;
}

//destructor
Dealer::~Dealer(){
    emptyHand();
}

//prints out in string form the card objects contained in the hand list
void Dealer::displayHand() {
	std::cout << "Dealer hand: " << std::endl;
	Node* root = hand.getTopNodePointer();
	while (root != nullptr) {
		Card current = root->getData();
		std::cout << current.toString() << std::endl;
		root = root->getNext();
	}
	std::cout << std::endl;
}

//add a new card to the hand list
void Dealer::addCard(Card newCard) {
	hand.add(newCard);
}

//returns the total value of the cards in the hand list
int Dealer::getCardTotal() {
	return cardTotal;
}

//updates the total value of the cards in the hand list
void Dealer::updateCardTotal(){
    cardTotal = 0;
	Node* root = hand.getTopNodePointer();
	Card rootCard = root->getData();
	while (root != nullptr) {
		
		//if the card is a Jack, Queen, or King
        if (rootCard.getFaceValue() == 11 || rootCard.getFaceValue() == 12 || rootCard.getFaceValue() == 13) {
			//its value is 10
            cardTotal+=10;
        }

		//if the card is an Ace
        else if (rootCard.getFaceValue() == 1) {
			//its value is 11 (according to our house rules)
            cardTotal+=11;
        }

		//if the card is a 2-10
        else {
            cardTotal+= rootCard.getFaceValue();
        }
		root = root->getNext();
		if (root != nullptr) {
			rootCard = root->getData();
		}
    }
}

//takes in a deck object by reference
//automatically has the dealer draw or not draw cards based on cardTotal
//announces when the dealer hits and whether the dealer hit 21 or went over
void Dealer::takeTurn(Deck& myDeck) {
    bool willTakeTurn = true;
    while (willTakeTurn) {
        displayHand();
        updateCardTotal();
        if (cardTotal == 21) {
            std::cout << "Dealer hit 21! \n";
            willTakeTurn = false;
        }
        else if (cardTotal > 21) {
            std::cout << "Dealer lost by going over 21. \n";
            willTakeTurn = false;
        }
        else {

			//the dealer is required to hit until their card total is greater than or equal to 17, at which point they can no longer hit
            if (cardTotal < 17) {
                std::cout <<"Dealer Hit. \n" <<std::endl;

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
void Dealer::emptyHand(){
    while (hand.size() > 0) {
        hand.remove(0);
    }
}
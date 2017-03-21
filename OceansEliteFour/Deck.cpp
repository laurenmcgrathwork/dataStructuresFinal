//
//  Deck.cpp
//  CardsSimulator
//
//  Created by Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath on 12/11/15.
//  Copyright (c) 2015 Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath. All rights reserved.
//

#include "Deck.h"
#include <iostream>


//constructor
Deck::Deck(){
    arr = new Card[52];
    numCards=52;
    
    //FORLOOP for suits
    for (int j = 0; j<4; j++) {
        //FORLOOP for card value
        for (int k = 1; k<=13; k++) {
                
            //Spades
            if (j==0) {
                arr[j*13+k-1] = Card("Spades",k);
            }
            //Clubs
            if (j==1) {
                arr[j*13+k-1] = Card("Clubs",k);
            }
            //Diamonds
            if (j==2) {
                arr[j*13+k-1] = Card("Diamonds",k);
            }
            //Hearts
            if (j==3) {
                arr[j*13+k-1] = Card("Hearts",k);
            }
        }
    }
}

//copy constructor
Deck::Deck(Deck &deckToCopy){
    
    numCards= deckToCopy.numCards;
    
    //FORLOOP for number of cards
    for (int i = 0; i<numCards; i++) {
        arr[i] = deckToCopy.arr[i];
    }

}

//destructor
Deck::~Deck() {
	delete[]arr;
	arr = nullptr;
}

//returns the number of Card objects currently in the Deck object
int Deck::getNumCards() {
    return numCards;
}

Card* Deck::getArr() {
	return arr;
}

//randomizes the order of the Card objects within the Deck object
void Deck::shuffle(){
    int i = 0;
    while (i<200) {
        //Generates 2 random indexes
        int index1 = rand() % numCards;
        int index2 = rand() % numCards;
        
        //Swaps position of 2 random indexes
        Card temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
        
        //counter
        i++;
    }
}

//prints the contents of the Deck array as a string
void Deck::toString(){
    for (int i = 0; i<numCards; i++) {
        std::cout << arr[i].toString() << std::endl;
    }
}

//removes a Card object from the Deck object and returns that Card object
Card Deck::draw() {
	//if there are no cards left to draw
	if (numCards <= 0) {
		throw PopFromEmptyException();
	}
	else {
		numCards--;
		Card top = arr[numCards];
		Card* tempArr = copyArrayPop(arr, numCards);
		delete[] arr;
		arr = tempArr;
		tempArr = nullptr;
		return top;
	}
}

//takes an array and copies it and creates a new array of the same number
//this new array must be deleted by whatever calls this function.
Card* Deck::copyArrayPop(const Card* arrayToCopy, const int size){
    Card* arrayCopy = new Card[size];

    for (int i = 0; i<size; i++) {
        arrayCopy[i]=arrayToCopy[i];
    }
    return arrayCopy;
}
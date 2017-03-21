//
//  Card.cpp
//  CardsSimulator
//
//  Created by Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath on 12/11/15.
//  Copyright (c) 2015 Will Suchanek, Irene Howard, Jonathan Chung, and Lauren McGrath. All rights reserved.
//

#include "Card.h"

//constructor
Card::Card(){
    suit = "NULL";
    faceVal = -1;
}

//copy constructor
Card::Card(std::string s, int face)
{
    suit = s;
    faceVal = face;
}

//gets the face value of a card
int Card::getFaceValue(){
    return faceVal;
}

//prints the values of a Card object in string form
std::string Card::toString() {
    if (1<faceVal && faceVal<11) {
        return  std::to_string(faceVal) + " of " + suit;
    }else if (faceVal==11){
        return  "Jack of " + suit;
        
    }else if (faceVal==12){
        return  "Queen of " + suit;
        
    }else if (faceVal==13){
        return  "King of " + suit;
    }else if (faceVal==1){
        return "Ace of " + suit;
    }
    return  "Error: Improper Card";
}
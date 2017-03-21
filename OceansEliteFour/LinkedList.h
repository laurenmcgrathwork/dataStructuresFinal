//
//  LinkedList.h
//  CardsSimulator
//
//  Created by Irene Howard on 10/29/15.
//  Copyright (c) 2015 Irene Howard. All rights reserved.
//

#ifndef _Lab7_LinkedList_h
#define _Lab7_LinkedList_h


#include "GenericItemType.h"
#include "ListADT.h"
#include "Node.h"

class LinkedList : public ListADT {
	
private:
	//insert data members here
	int listSize;
	Node* topNodePointer;

public:
	//Constructor
	LinkedList();

	//Copy Constructor: : makes a new deep copy of the LinkedList parameter
	LinkedList(const LinkedList& linkedListToCopy);

	//Destructor
	~LinkedList();


	//Appends the specified element to the end of this list
	void add(ItemType itemToAdd);


	//returns a copy of the element at the specififed position in the list
	//throws IndexOutOfBoundsException if index is invalid
	ItemType get(int index);


	//Inserts the specified element at the specified position in this list
	//throws IndexOutOfBoundsException if index is invalid
	void add(int index, ItemType itemToAdd);


	//Removes the element at the specified position in this list
	//return the item that you remove
    //throws IndexOutOfBoundsException if index is invalid
	ItemType remove(int index);

	//Returns the number of items in this list
	int size();

	//returns topNodePointer
	Node* getTopNodePointer();

};

#endif
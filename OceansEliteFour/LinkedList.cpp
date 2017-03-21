//
//  LinkedList.cpp
//  CardsSimulator
//
//  Created by Irene Howard on 10/29/15.
//  Copyright (c) 2015 Irene Howard. All rights reserved.
//

#include "LinkedList.h"
#include "GenericItemType.h"


//Constructor:  creates a new, empty Linked List
LinkedList::LinkedList() {
	listSize = 0;
	topNodePointer = nullptr;
}

//Copy Constructor:  makes a new deep copy of the Linked List parameter
LinkedList::LinkedList(const LinkedList& linkedListToCopy) {
	
	Node* tempPtr = linkedListToCopy.topNodePointer;
	listSize = 0;
	while (tempPtr != nullptr) {
		ItemType newData = tempPtr->getData();
		add(newData);
		tempPtr = tempPtr->getNext();
	}

}

//Destructor
LinkedList:: ~LinkedList() {

	while (listSize > 0) {
		remove(0);
	}
    topNodePointer=nullptr;
}

//Appends the specified element to the end of this list
void LinkedList::add(ItemType itemToAdd) {
	Node* myNode = new Node(itemToAdd);

	if (listSize == 0) {
		myNode->setNext(topNodePointer);

		//make topNodePointer the first node again
		topNodePointer = myNode;
	}
	else {
		Node* prevNodePointer = topNodePointer;
		//makes prevNode point to the node at the index one less than the passed index
		for (int i = 0; i < (listSize - 1); i++) {
			prevNodePointer = (prevNodePointer)->getNext();
		}
		prevNodePointer->setNext(myNode);
		myNode->setNext(NULL);
	}
	listSize++;

}

//returns a copy of the element at the specififed position in the list
//throws IndexOutOfBoundsException if index is invalid
ItemType LinkedList::get(int index) {
	
	if (index > (listSize - 1) || index<0) {
		throw IndexOutOfBoundsException();
	}

	Node* myNodePointer = topNodePointer;

	for (int i = 0; i < index; i++) {
		
		//get next node, replace node variable
		myNodePointer = (myNodePointer)->getNext();
	}

	//using both . and -> so I remember how to use both
	return (*myNodePointer).getData();

}

//Inserts the specified element at the specified position in this list
//throws IndexOutOfBoundsException if index is invalid
void LinkedList::add(int index, ItemType itemToAdd) {

	//create a new node with this data.
	//make the new node point to the node with the index equal to the passed index
	//make the node with the index one less than the passed index point to it

	if (index<0 || index > listSize) {
		throw IndexOutOfBoundsException();
	}


	Node* myNode = new Node(itemToAdd);

	if (index == 0) {
		myNode->setNext(topNodePointer);

		//make topNodePointer the first node again
		topNodePointer = myNode;
	}

	else if (index == listSize) {
		Node* prevNodePointer = topNodePointer;
		//makes prevNode point to the node at the index one less than the passed index
		for (int i = 0; i < (index - 1); i++) {
			prevNodePointer = (prevNodePointer)->getNext();
		}
		prevNodePointer->setNext(myNode);
		myNode->setNext(NULL);
	}


	else {
		Node* prevNodePointer = topNodePointer;
		//makes prevNode point to the node at the index one less than the passed index
		for (int i = 0; i < (index - 1); i++) {
			prevNodePointer = (prevNodePointer)->getNext();
		}

		Node* nextNodePointer = topNodePointer;
		//makes nextNodePointer point to the node at the current passed index
		for (int i = 0; i < index; i++) {
			nextNodePointer = (nextNodePointer)->getNext();
		}


		myNode->setNext(nextNodePointer);
		prevNodePointer->setNext(myNode);
	}

	//increase the size of the list, because a new node was just added
	listSize++;
}


//Removes the element at the specified position in this list
//return the item that you remove
//throws IndexOutOfBoundsException if index is invalid
ItemType LinkedList::remove(int index) {

	if (index<0 || index >= listSize) {
		throw IndexOutOfBoundsException();
	}

	Node* nodeToRemove = topNodePointer;

	if (index == 0) {
		topNodePointer = topNodePointer->getNext();
	}

	else if (index == (listSize - 1)) {
		for (int i = 0; i < index; i++) {
			nodeToRemove = (nodeToRemove)->getNext();
		}
		Node* prevNodePointer = topNodePointer;

		//makes prevNode point to the node at the index one less than the passed index
		for (int i = 0; i < (index - 1); i++) {
			prevNodePointer = (prevNodePointer)->getNext();
		}
		prevNodePointer->setNext(nullptr);

	}

	
	else {
		for (int i = 0; i < index; i++) {
			nodeToRemove = (nodeToRemove)->getNext();
		}

		//Node* tempPointer = topNodePointer;
		//tempPointer->setNext(nodeToRemove);


		Node* prevNodePointer = topNodePointer;
		//makes prevNode point to the node at the index one less than the passed index
		for (int i = 0; i < (index - 1); i++) {
			prevNodePointer = (prevNodePointer)->getNext();
		}

		Node* nextNodePointer = topNodePointer;
		//makes nextNodePointer point to the node at the node one greater than the passed index
		for (int i = 0; i < index + 1; i++) {
			nextNodePointer = (nextNodePointer)->getNext();
		}

		prevNodePointer->setNext(nextNodePointer);
		nodeToRemove->setNext(NULL);
		//tempPointer->setNext(NULL);
	}

	ItemType data = nodeToRemove->getData();
	//set prevNodePointer to null
	delete nodeToRemove;

	listSize --;

	return data;
}

//Returns the number of items in this list
int LinkedList::size() {
	return listSize;
}


Node* LinkedList::getTopNodePointer() {
	return topNodePointer;
}

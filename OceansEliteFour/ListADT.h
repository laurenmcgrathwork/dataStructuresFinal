//
//  ListADT.h
//  Lab7-Lists
//
//  Created by Toby Dragon on 10/21/15.
//  Copyright (c) 2015 Toby Dragon. All rights reserved.
//

#ifndef Lab7_Lists_ListADT_h
#define Lab7_Lists_ListADT_h

#include "GenericItemType.h"

class IndexOutOfBoundsException : std::exception{ };

class ListADT{
public:

    //Appends the specified element to the end of this list
    virtual void add(ItemType itemToAdd) =0;
    
    //returns a copy of the element at the specififed position in the list
    //throws IndexOutOfBoundsException if index is invalid
    virtual ItemType get(int index) =0;
    
    //Inserts the specified element at the specified position in this list
    //throws IndexOutOfBoundsException if index is invalid
    virtual void add(int index, ItemType itemToAdd) =0;
    
    //Removes the element at the specified position in this list
    //Returns a copy of the item
    //throws IndexOutOfBoundsException if index is invalid
    virtual ItemType remove(int index) =0;
    
    //Returns the number of items in this list
    virtual int size() =0;
    
    //Destructor
    virtual ~ListADT(){};
    
};

#endif

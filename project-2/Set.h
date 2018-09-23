#pragma once
#include "SetInterface.h"

template <class ItemType>
class Set : public SetInterface<ItemType> {
private:
    static const int DEFAULT_SET_SIZE = 4; // for testing purposes we will keep the set small
    ItemType items_[DEFAULT_SET_SIZE]; // array of set items
    int item_count_;                  // current count of set items
    int max_items_;                   // max capacity of the set
    // post: Either returns the index of target in the array items_ 
    // or -1 if the array does not contain the target
    int getIndexOf(const ItemType& target) const;
    
public:
    //Default Constructor
    Set();
    //Returns the current size of the Set
    //@return: current size of set
    virtual int getCurrentSize() const;
    //@return: true if the set is empty, false otherwise
    virtual bool isEmpty() const;
    //adds newEntry at the end of the set
    //@param: item to be added
    //@return: true if the item was added successfully, false otherwise
    virtual bool add(const ItemType& newEntry);
    //removes an item in the set, if it exists
    //@param: item to be removed
    //@return: true if the item was removed successfully, false otherwise
    virtual bool remove(const ItemType& anEntry);
    //removes everything in the set
    virtual void clear();
    //checks if an item is in the set
    //@param: the entry to be checked
    //@return: true if the item is in the set, false otherwise
    virtual bool contains(const ItemType& anEntry) const;
    //converts a set to a vector
    //@return: a vector contain all the elements of the set
    virtual std::vector<ItemType> toVector() const;
};
#include "Set.cpp"
#include "Set.h"
#include <vector>

//Initialize item_count_  and max_items_
template<class ItemType>
Set<ItemType>::Set() {
    item_count_ = 0;
    max_items_ = DEFAULT_SET_SIZE;
}


//Find the index of a selected targets
//@param: the item to look for
//@return: the index of target or -1 if it doesn't exist
template<class ItemType>
int Set<ItemType>::getIndexOf(const ItemType& target) const {
    for (int i = 0; i < item_count_; i++) {
        if (items_[i] == target) {
            return i;
        }
    }
    return -1;
}


//@return: the current size of the set
template<class ItemType>
int Set<ItemType>::getCurrentSize() const { return item_count_; } 

//@return: true if the set is empty false otherwise
template<class ItemType>
bool Set<ItemType>::isEmpty() const { return item_count_ == 0; }

//Adds an item to the set if there is space and the item is unique
//@post: Set with item added at the end
//@return:
template<class ItemType>
bool Set<ItemType>::add(const ItemType& item) {
    if (item_count_ == max_items_ || this->contains(item))
        return false;
    else {
        items_[item_count_] = item;
        item_count_++;
        return true;
    }
}

//
//@pre: 
//@post:
//@return:
template<class ItemType>
bool Set<ItemType>::remove(const ItemType& item) {
    int itemIndex = this->getIndexOf(item);
    if (itemIndex != -1 && item_count_ > 0) {
        items_[itemIndex] = items_[--item_count_];
        return true;
    } else {
        return false;
    }
}

//
//@pre: 
//@post:
//@return:
template<class ItemType>
void Set<ItemType>::clear() {
    item_count_ = 0;
}

//
//@pre: 
//@post:
//@return:
template<class ItemType>
bool Set<ItemType>::contains(const ItemType& item) const {
    return this->getIndexOf(item) != -1;
}

//
//@pre: 
//@post:
//@return:
template<class ItemType>
std::vector<ItemType> Set<ItemType>::toVector() const {
    std::vector<ItemType> vec;
    for (int i = 0; i < item_count_; i++) {
        vec.push_back(items_[i]);
    }
    return vec;
}
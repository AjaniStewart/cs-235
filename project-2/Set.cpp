#include "Set.h"
#include <vector>

template<class ItemType>
Set<ItemType>::Set() {
    item_count_ = 0;
    max_items_ = DEFAULT_SET_SIZE;
}

template<class ItemType>
int Set<ItemType>::getIndexOf(const ItemType& target) const {
    for (int i = 0; i < item_count_; i++) {
        if (items_[i] == target) {
            return i;
        }
    }
    return -1;
}

template<class ItemType>
int Set<ItemType>::getCurrentSize() const { return item_count_; } 

template<class ItemType>
bool Set<ItemType>::isEmpty() const { return item_count_ == 0; }

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

template<class ItemType>
bool Set<ItemType>::remove(const ItemType& item) {
    if (this->contains(item)) {
        int itemIndex = this->getIndexOf(item);
        for (int i = itemIndex; i < item_count_; i++) {
            items_[i] = items_[i+1];
        }
        item_count_--;
        return true;
    } else {
        return false;
    }
}

template<class ItemType>
void Set<ItemType>::clear() {
    for (auto& e : items_) {
        this->remove(e);
    }
    item_count_ = 0;
}

template<class ItemType>
bool Set<ItemType>::contains(const ItemType& item) const {
    for (int i = 0; i < item_count_; i++) {
        if (items_[i] == item)
            return true;
    }
    return false;
}

template<class ItemType>
std::vector<ItemType> Set<ItemType>::toVector() const {
    std::vector<ItemType> vec;
    for (int i = 0; i < item_count_; i++) {
        vec.push_back(items_[i]);
    }
    return vec;
}
//@author Ajani Stewart
//Playlist with linked list implementation
//@file PlayList.cpp
//@date 9/28/18
//CSCI 235, Fall 2018, Project 3

#include <iostream>
#include <vector>

#include "PlayList.h"
#include "Song.h"

//private
//@return: a pointer to the last node(song) in the playlist if the playlist is
//not empty, returns a nullptr otherwise
Node<Song>* PlayList::getPointerToLastNode() const {
  return tail_ptr_;
};

//default constructor
PlayList::PlayList() {
  tail_ptr_ = nullptr;
  head_ptr_ = nullptr;
  item_count_ = 0;
}

//paramertized constructor
PlayList::PlayList(const Song& song) {
  Node<Song>* new_song = new Node<Song>(song);
  head_ptr_ = new_song;
  tail_ptr_ = new_song;
  item_count_ = 1;
}

//copy constructor
PlayList::PlayList(const PlayList& playlist) {
  item_count_ = playlist.item_count_;
  if (playlist.isEmpty()) {
    head_ptr_ = nullptr;
    tail_ptr_ = nullptr;
  } else {
    Node<Song>* first_node = new Node<Song>;
    first_node->setItem(playlist.head_ptr_->getItem());
    head_ptr_ = first_node;
    Node<Song>* cur_ptr = playlist.head_ptr_->getNext();
    head_ptr_->setNext(cur_ptr);
    while (cur_ptr != nullptr) {
      Node<Song>* new_node = new Node<Song>;
      new_node->setItem(cur_ptr->getItem());
      new_node->setNext(cur_ptr->getNext());
      if (new_node->getNext() == nullptr) {
        tail_ptr_ = new_node;
      }
      cur_ptr = cur_ptr->getNext();
    }
  }
}

//destructor
PlayList::~PlayList() {
  clear();
}
//adds a song to the end of a playlist
//@return true if the addition was successfully,
//false otherwise
bool PlayList::add(const Song& new_song) {
  if (this->isEmpty()) {
    Node<Song>* song = new Node<Song>(new_song);
    head_ptr_ = song;
    tail_ptr_ = song;
    item_count_ = 1;
    return true;
  } else {
      if (this->contains(new_song)) {
        return false;
    } else {
      Node<Song>* song = new Node<Song>(new_song);
      tail_ptr_->setNext(song);
      tail_ptr_ = tail_ptr_->getNext();
      item_count_++;
      return true;
    }
  }
}
//TODO: Finish this!
Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& prev_ptr) const {
  if (head_ptr_->getItem() == target) {
    Node<Song>* h_ptr = head_ptr_;
    return h_ptr;
  }
  Node<Song>* cur_ptr = head_ptr_;
}


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
  Node<Song>* cur_ptr = head_ptr_;
  while (cur_ptr->getNext() != nullptr) {
    cur_ptr = cur_ptr->getNext();
  }
  return cur_ptr;
}

//default constructor
PlayList::PlayList() {
  tail_ptr_ = nullptr;
}

//paramertized constructor
PlayList::PlayList(const Song& song) {
  Node<Song>* new_song = new Node<Song>(song);
  head_ptr_ = new_song;
  tail_ptr_ = new_song;
  item_count_ = 1;
}

//copy constructor
PlayList::PlayList(const PlayList& playlist) : LinkedSet<Song>(playlist) {
  tail_ptr_ = getPointerToLastNode();
}

//destructor
PlayList::~PlayList() {
  unloop();
  clear();
}
//adds a song to the end of a playlist
//@param: song to be added
//@return: true if the addition was successfully, false otherwise
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
//private member function that return a pointer a node in the list and updates
//prev_ptr to point to the node before the pointer
//@param: target song, and a node pointer to previous pointer
//@return: a pointer to the target if it is in the playlist, nullptr otherwise
//@post: prev_ptr points to the node before the target, if is not the head_ptr_
Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& prev_ptr) const { 
  Node<Song>* cur_ptr = new Node<Song>;
  cur_ptr = head_ptr_;
  while (cur_ptr != nullptr) {
    if (cur_ptr->getItem() == target) {
      return cur_ptr;
    } else {
      prev_ptr = cur_ptr;
      cur_ptr = cur_ptr->getNext();
    }
  }
  return nullptr;
}

//removes a song from the playlist, if it exists, and retains the order of the playlist
//@param: song to be removed
//@return: true if the song was successfully removed, false otherwise
bool PlayList::remove(const Song& target) {
  if (isEmpty()) { return false; }
  Node<Song>* prev_ptr;
  Node<Song>* ptr_to_target = getPointerTo(target, prev_ptr);
  if (ptr_to_target == nullptr) {
    return false;
  } else {
    if (ptr_to_target == head_ptr_) {
      Node<Song>* temp_ptr = head_ptr_;
      head_ptr_ = head_ptr_->getNext();
      delete temp_ptr;
      temp_ptr = nullptr;
    } else if (ptr_to_target == tail_ptr_) {
      Node<Song>* temp_ptr = tail_ptr_;
      tail_ptr_ = prev_ptr;
      tail_ptr_->setNext(nullptr);
      delete temp_ptr;
      temp_ptr = nullptr;
    } else {
      prev_ptr->setNext(ptr_to_target->getNext());
      delete ptr_to_target;
      ptr_to_target = nullptr;
    }

    item_count_--;
    return true;
  }
}

void PlayList::loop() {
  tail_ptr_->setNext(head_ptr_);
}

void PlayList::unloop() {
  tail_ptr_->setNext(nullptr);
}

void PlayList::displayPlayList() {
  std::vector<Song>playlist_vector = toVector();
  for (const auto& song : playlist_vector) {
    std::cout << "* Title: " << song.getTitle() << "* Author: "
    << song.getAuthor() << "* Album: " <<  song.getAlbum() << " *\n"; 
  }
  std::cout << "End of playlist \n";
}


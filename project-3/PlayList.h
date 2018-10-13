//@author Ajani Stewart
//Playlist with linked list implementation
//@file PlayList.h
//@date 9/28/18
//CSCI 235, Fall 2018, Project 3

#pragma once

#include "LinkedSet.h"
#include "Song.h"

class PlayList : public LinkedSet<Song> {
private:
  Node<Song>* tail_ptr_; //Pointer to the last node
  Node<Song>* getPointerToLastNode() const;
  bool looped = false;

public:
  PlayList();                     //default constructor
  PlayList(const Song& a_song);   //paramertized constructor
  PlayList(const PlayList& a_play_list); //copy constructor
  ~PlayList();                    //destructor

  bool add(const Song& new_song) override;
  bool remove(const Song& song) override;
  // post: previous_ptr is null if target is not in PlayList or if target is the
  // first node, otherwise it points to the node preceding target
  // @return: either a pointer to the node containing target
  // or the null pointer if the target is not in the PlayList.
  Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const;
  void loop();
  void unloop();
  void displayPlayList();

};
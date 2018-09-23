#pragma once
#include "Set.h"
#include "Song.h"

class PlayList {
private:
    Set<Song> playlist_;

public:
    //Default constructor
    PlayList();
    //Parameterized constructor
    PlayList(const Song& a_song);
    //@return: the number of songs 
    int getNumberOfSongs() const;
    //@return: true if the playlist is empty false otherwise
    bool isEmpty() const;
    //@param: song to be added to the playlist
    //@return: true if the song was added successfully false otherwise
    bool addSong(const Song& new_song);
    //@param: song to be removed if it exists
    //@return: true if the song was removed successfully, false otherwise
    bool removeSong(const Song& a_song);
    //Removes all the songs in the playlist
    void clearPlayList();
    //Displays the playlist to standard out
    void displayPlayList() const;
};
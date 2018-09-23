#include "PlayList.h"
#include <iostream>
#include "Song.h"
#include <vector>

//default constructor: creates an empty playlist
PlayList::PlayList() { }
//Paramertized constructer: initalizes the playlist with a song
PlayList::PlayList(const Song& song) {
    playlist_.add(song);
}
//@return: the number of songs on the playlist
int PlayList::getNumberOfSongs() const { return playlist_.getCurrentSize(); }
//@return: true if the playlist is empty, false otherwise
bool PlayList::isEmpty() const { return playlist_.isEmpty(); }
//adds a song to the playlist if its not full and does not already exist
//@param: song to be added
//@return: true of the song was added correctly, false otherwise
bool PlayList::addSong(const Song& song) { return playlist_.add(song); }
//removes a song in the playlist, if it exists
//@param: the song to be removed
//@return: true id the song was removed successfully, false otherwise
bool PlayList::removeSong(const Song& song) { return playlist_.remove(song); }
//removes all songs on the playlist
void PlayList::clearPlayList() { return playlist_.clear(); }
//prints songs in playlist to standard out
void PlayList::displayPlayList() const {
    std::vector<Song> playList_vector = playlist_.toVector();
    for (int i = 0, end = playlist_.getCurrentSize(); i < end; ++i) {
        Song currentSong = playList_vector[i];
        std::cout << "* Title: "<< currentSong.getTitle() << " * Author: " << currentSong.getAuthor();
        std::cout << " * Album: " << currentSong.getAlbum() << " *\n";
    }
    std::cout << "End of playlist\n";
}


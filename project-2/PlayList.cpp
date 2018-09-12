#include "PlayList.h"
#include <iostream>
#include "Song.h"
#include <vector>

PlayList::PlayList() { }

PlayList::PlayList(const Song& song) {
    playlist_.add(song);
}

int PlayList::getNumberOfSongs() const { return playlist_.getCurrentSize(); }

bool PlayList::isEmpty() const { return playlist_.isEmpty(); }

bool PlayList::addSong(const Song& song) { return playlist_.add(song); }

bool PlayList::removeSong(const Song& song) { return playlist_.remove(song); }

void PlayList::clearPlayList() { return playlist_.clear(); }

void PlayList::displayPlayList() const {
    std::vector<Song> playList_vector = playlist_.toVector();
    for (int i = 0, end = playlist_.getCurrentSize(); i < end; ++i) {
        Song currentSong = playList_vector[i];
        std::cout << "* Title: "<< currentSong.getTitle() << " * Author: " << currentSong.getAuthor();
        std::cout << " * Album: " << currentSong.getAlbum() << " *\n";
    }
    std::cout << "End of playlist\n";
}


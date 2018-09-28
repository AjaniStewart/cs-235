#include "Song.h"
#include <string>

//default constructor
Song::Song() { }

//parameterized contructor
//initailizes song woth title, author, and album
Song::Song(const std::string& title, const std::string& author, const std::string& album)
    : title_{title}, author_{author}, album_{album} { }

//Setters
void Song::setTitle(std::string title) { title_ = title; }
void Song::setAuthor(std::string author) { author_ = author; }
void Song::setAlbum(std::string album) { album_ = album; }

//getters
std::string Song::getTitle() const { return title_; }
std::string Song::getAuthor() const { return author_; }
std::string Song::getAlbum() const { return album_; }

//overloaded equality operator
//songs are equal if titles, authors, and albums are the same
bool operator==(const Song& lhs, const Song& rhs) {
    return lhs.title_ == rhs.title_ && lhs.author_ == rhs.author_ && lhs.album_ == rhs.album_;
}
#pragma once
#include <string>

class Song {
private:
    std::string title_;
    std::string author_;
    std::string album_;

public:
    //Default constructor
    Song();
    //parameterized constructor
    Song(const std::string& title, const std::string& author="", const std::string& album="");
    //interface for setting title
    void setTitle(std::string title);
    //interface for setting author
    void setAuthor(std::string author);
    //interface for setting album
    void setAlbum(std::string album);
    //interface for getting title
    std::string getTitle() const;
    //interface for getting Author
    std::string getAuthor() const;
    //interface for getting Album
    std::string getAlbum() const;
    
    //overloaded equality operator
    //@param: the songs being compared
    //@return: true of both songs' titles, authors, and albums are the same
    //          false otherwise
    friend bool operator==(const Song& lhs, const Song& rhs);
};
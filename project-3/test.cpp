#include <iostream>

#include "Song.h"
#include "PlayList.h"

int main() {

	std::cout << std::boolalpha;

	Song song1("song1","author1","album1");
	Song song2("song2", "author2", "album2");
	Song song3("song3", "author3", "album3");
	Song song4("song4", "author4", "album4");
	Song song5("song5", "author5", "album5");


	PlayList playlist1(song1);
	playlist1.add(song2);
	playlist1.add(song3);
	playlist1.add(song4);
	playlist1.add(song5);

	playlist1.displayPlayList();

	PlayList playlist2 = playlist1;
	playlist2.displayPlayList();
}
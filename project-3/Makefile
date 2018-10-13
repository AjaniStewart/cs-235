CXXFLAGS=-std=c++14
main: main.o PlayList.o Song.o #Node.o
	g++ $(CXXFLAGS) -o main main.o PlayList.o Song.o #Node.o

test: test.o PlayList.o Song.o
	g++ $(CXXFLAGS) -o test test.o PlayList.o Song.o #Node.o

main.o: main.cpp PlayList.h Song.h
	g++ $(CXXFLAGS) -c main.cpp

PlayList.o: PlayList.cpp PlayList.h
	g++ $(CXXFLAGS) -c PlayList.cpp

Song.o:Song.cpp Song.h
	g++ $(CXXFLAGS) -c Song.cpp

test.o: test.cpp PlayList.h Song.h
	g++ $(CXXFLAGS) -c test.cpp



#Node.o: Node.cpp Node.h
	#g++ $(CXXFLAGS) -c Node.cpp

debug: CXXFLAGS:=$(CXXFLAGS) -g -fsanitize=address,undefined

debug: main

clean:
	rm -f main.o PlayList.o Song.o Node.o test.o main test 

run:
	UBSAN_OPTIONS="print_stacktrace=1" ./main

run_test:
	./test
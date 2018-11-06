CXXFLAGS=-std=c++14
main: main.o MazeSolver.o
	g++ $(CXXFLAGS) -o main main.o MazeSolver.o


main.o: main.cpp MazeSolver.h
	g++ $(CXXFLAGS) -c main.cpp

MazeSolver.o: MazeSolver.cpp
	g++ $(CXXFLAGS) -c MazeSolver.cpp


debug: CXXFLAGS:=$(CXXFLAGS) -g -fsanitize=address,undefined

debug: main

clean:
	rm -f main.o MazeSolver.o main

run:
	UBSAN_OPTIONS="print_stacktrace=1" ./main

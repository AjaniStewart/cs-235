CXXFLAGS = -std=c++14

test: tests.o SortingTests.o
	g++ $(CXXFLAGS) -o test tests.o SortingTests.o

tests.o: tests.cpp SortingTests.hpp
	g++ $(CXXFLAGS) -c tests.cpp

SortingTests.o: SortingTests.cpp
	g++ $(CXXFLAGS) -c SortingTests.cpp

debug: CXXFLAGS:=$(CXXFLAGS) -g -fsanitize=address,undefined

debug: test

run_test:
	UBSAN_OPTIONS="print_stacktrace=1" ./test

clean:
	rm -f SortingTests.o tests.o test
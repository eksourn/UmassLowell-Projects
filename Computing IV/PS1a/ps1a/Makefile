CC = g++
FLAGS = -Werror -Wall -pedantic -ansi -std=c++11 -g

all: ps1a

test.o: test.cpp
	$(CC) $(FLAGS) -o test.o -c test.cpp

FibLFSR.o: FibLFSR.cpp FibLFSR.h
	$(CC) $(FLAGS) -o FibLFSR.o -c FibLFSR.cpp

ps1a: FibLFSR.o test.o
	$(CC) -o ps1a test.o FibLFSR.o -lboost_unit_test_framework

clean:
	rm *.o

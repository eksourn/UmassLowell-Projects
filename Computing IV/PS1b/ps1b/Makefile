CXX = g++
CXXFLAGS = -Werror -Wall -pedantic -ansi -std=c++11 -g
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: PhotoMagic

PhotoMagic.o: PhotoMagic.cpp
	$(CXX) $(CXXFLAGS) -o PhotoMagic.o -c PhotoMagic.cpp

FibLFSR.o: FibLFSR.cpp FibLFSR.h
	$(CXX) $(CXXFLAGS) -o FibLFSR.o -c FibLFSR.cpp

PhotoMagic: FibLFSR.o PhotoMagic.o
	$(CXX) -o PhotoMagic PhotoMagic.o FibLFSR.o $(LDLIBS)

clean:
	rm *.o

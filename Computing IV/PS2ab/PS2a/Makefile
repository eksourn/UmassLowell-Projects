CXX = g++
CXXFLAGS = -Werror -Wall -pedantic -ansi -std=c++11 -g
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: NBody

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -o main.o -c main.cpp

nbody.o: nbody.cpp nbody.h
	$(CXX) $(CXXFLAGS) -o nbody.o -c nbody.cpp

NBody: main.o nbody.o
	$(CXX) -o NBody main.o nbody.o $(LDLIBS)

clean:
	rm *.o



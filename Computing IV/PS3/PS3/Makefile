CXX = g++
CXXFLAGS = -Werror -Wall -pedantic -std=c++14 -g
LDLIBS = -lboost_unit_test_framework -lsfml-system

all: ED

ED.o: ED.cpp ED.h
	$(CXX) $(CXXFLAGS) -o ED.o -c ED.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -o main.o -c main.cpp

ED: ED.o main.o
	$(CXX) -o ED ED.o main.o $(LDLIBS)

clean:
	rm *.o ED

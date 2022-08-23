CXX = g++
CXXFLAGS = -Werror -Wall -pedantic -std=c++11 -g
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: ps5

Triangle.o: Triangle.cpp Triangle.h
	$(CXX) $(CXXFLAGS) -o Triangle.o -c Triangle.cpp

TFractal.o: TFractal.cpp
	$(CXX) $(CXXFLAGS) -o TFractal.o -c TFractal.cpp

ps5: Triangle.o TFractal.o
	$(CXX) -o ps5 TFractal.o Triangle.o $(LDLIBS)

clean:
	rm *.o ps5

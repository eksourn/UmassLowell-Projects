CXX = g++
CXXFLAGS = -Werror -Wall -pedantic -std=c++11 -g
LDLIBS = -lboost_unit_test_framework -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: KSGuitarSim 

CircularBuffer.o: CircularBuffer.cpp CircularBuffer.h
	$(CXX) $(CXXFLAGS) -o CircularBuffer.o -c CircularBuffer.cpp

StringSound.o: StringSound.cpp StringSound.h
	$(CXX) $(CXXFLAGS) -o StringSound.o -c StringSound.cpp

KSGuitarSim.o: KSGuitarSim.cpp
	$(CXX) $(CXXFLAGS) -o KSGuitarSim.o -c KSGuitarSim.cpp

KSGuitarSim: KSGuitarSim.o CircularBuffer.o StringSound.o
	$(CXX) -o KSGuitarSim KSGuitarSim.o CircularBuffer.o StringSound.o $(LDLIBS)

clean:
	rm *.o KSGuitarSim

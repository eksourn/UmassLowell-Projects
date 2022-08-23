CXX = g++
CXXFLAGS = -Werror -Wall -pedantic -std=c++11 -g
LDLIBS = -lboost_regex -lboost_date_time

all: ps6

ps6.o: ps6.cpp
	$(CXX) $(CXXFLAGS) -o ps6.o -c ps6.cpp

ps6: ps6.o
	$(CXX) ps6.o -o ps6 $(LDLIBS)

clean:
	rm *.o ps6

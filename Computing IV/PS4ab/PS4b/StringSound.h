// Copyright 2021 Ethan Sourn
#pragma once
#include <SFML/Audio.hpp>
#include <functional>
#include <vector>
#include "/usr/cs/undergrad/2021/esourn/COMPIV/PS4b/CircularBuffer.h"

//  Sampling rate
const int s_rate = 44100;
//  Decay factor
const double decay_factor = 0.996;
class StringSound {
  public:
    //  Create a guitar string sound w/ given freq
    explicit StringSound(double frequency);
    //  Create a guitar str w/ size and init values
    explicit StringSound(std::vector<sf::Int16> init);
    //  No copy const
    StringSound(const StringSound &obj) {}
    //  Pluck guitar str by replacing buffer w/ random values (white noise)
    void pluck();
    //  Advance simulate by one time step
    void tic();
    //  Return current sample
    sf::Int16 sample();
    //  Return num of times tic was called so far
    int time();
    //  Destructor
    //  ~StringSound() { delete _cb; }
  private:
    CircularBuffer _cb;
    //  Size of Circular Buffer
    int N;
    //  Time interval
    int _time;
};

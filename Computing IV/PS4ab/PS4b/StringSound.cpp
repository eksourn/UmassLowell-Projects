//  Copyright 2021 Ethan Sourn
#include <random>
#include <cmath>
#include <vector>
#include "/usr/cs/undergrad/2021/esourn/COMPIV/PS4b/StringSound.h"

StringSound::StringSound(double frequency) {
  try {
  //  Get capacity of buffer
  if (frequency == 0)
    throw std::invalid_argument("Error in StringSound(double)!\n");
  } catch(const std::invalid_argument& ia) {
      printf("Error: Invalid argument in string sound constructor!\n");
      throw ia;
  }
  double n = ceil(s_rate / frequency);
  _cb(n);
  //  Create new object
  //  _cb = new CircularBuffer(N);
  //  Fill buffer w/ 0s
  /*while (_cb->isFull() == false) {
    _cb->enqueue(0);
  }*/
  _time = 0;
}

StringSound::StringSound(std::vector<sf::Int16> init) : _cb(init.size()) {
  std::vector<sf::Int16>::iterator iter;
  //  Enqueue data
  for (iter = init.begin(); iter < init.end(); iter++)
    _cb.enqueue(*iter);
  // Init time to 0
  _time = 0;
}

void StringSound::pluck() {
  // Empty buffer
  _cb.nFront = 0;
  _cb.nBack = 0;
  _cb.nSize = 0;
  //  Generate random values over int16_t range (-32768, 32767)
  std::default_random_engine generator;
  std::uniform_int_distribution<sf::Int16> distribution(-32768, 32767);
  //  Bound distribution and generator together
  auto value = std::bind(distribution, generator);
  //  Fill buffer with random values
  while (!_cb.isFull()) {
    _cb.enqueue(value());
  }
}

void StringSound::tic() {
  //  Get first element and dequeue
  sf::Int16 s1 = _cb.dequeue();
  //  Get second element
  sf::Int16 s2 = _cb.peek();
  //  Apply Karplus_Strong Algorithm
  //  Yt = 0.996 * ((Yt-p + Yt-p+1) / 2)
  sf::Int16 Yt = decay_factor * ((s1 + s2) / 2);
  //  Enqueue Yt
  _cb.enqueue(Yt);
  //  Update tic counter
  _time++;
}

sf::Int16 StringSound::sample() {
  //  Get front of buffer and return
  sf::Int16 curr_sample = _cb.peek();
  return curr_sample;
}

int StringSound::time() {
  return _time;
}

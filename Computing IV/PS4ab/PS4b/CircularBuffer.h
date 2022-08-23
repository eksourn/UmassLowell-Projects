//  Copyright 2021 Ethan Sourn
#pragma once
#include <stdint.h>
#include <stdexcept>
#include <vector>
#include <cstdio>

class CircularBuffer {
 public:
  //  Default Constructor
  CircularBuffer() : nCapacity(0), nSize(0), nFront(0) {}
  //  Create empty buf w/ given max
  explicit CircularBuffer(int capacity);
  //  Return number of items currently in the buffer
  int size();
  //  Is the buffer empty (size equals zero)?
  bool isEmpty();
  //  Is the buffer full (size equals capacity)?
  bool isFull();
  //  Add item x to the end
  void enqueue(int16_t x);
  //  Delete and return item from the front
  int16_t dequeue();
  //  Return (but do not delete) item from the front
  int16_t peek();
  //  Empty circular buffer
  //  void empty();
 private:
  // Size of buffer
  int nCapacity;
  int16_t _x;
  // Current elements in buffer
  int nSize;
  // Front element
  int nFront;
  // Back element
  int nBack;
  std::vector<int16_t> nBuffer;
};

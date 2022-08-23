//  Copyright 2021 Ethan Sourn
#include "/usr/cs/undergrad/2021/esourn/COMPIV/PS4a/CircularBuffer.h"
//  Set private variables and create an empty ring buffer
CircularBuffer::CircularBuffer(int capacity) {
  try {
    if (capacity < 1)
      throw std::invalid_argument("constructor: capacity must be > 0\n");
  }catch(const std::invalid_argument& err) {
      printf("Error! constructor: capacity must be > 0\n");
      throw err;
  }
  //  Reserve/allocate space for buffer
  nBuffer.reserve(capacity);
  //  Set private variables
  nFront = 0;
  nSize = 0;
  nCapacity = capacity;
}
//  Should simply return the number of items in the buffer
int CircularBuffer::size() {
  return nSize;
}
//  Should return true if buffer is empty or false
bool CircularBuffer::isEmpty() {
  if (nSize > 0) {
    return false;
  } else {
    return true;
    }
}
//  Should return true if capacity is at max or not
bool CircularBuffer::isFull() {
  if (nSize < nCapacity) {
    return false;
  } else {
    return true;
    }
}
//  Should enqueue a int16_t value into the circular buffer
void CircularBuffer::enqueue(int16_t x) {
  try {
    if (isFull())
      throw std::runtime_error("enqeue: can't enqueue to a full ring\n");
  }catch(const std::runtime_error& err) {
      printf("Error! enqueue: can't enqueue to a full ring\n");
      throw err;
  }
  // Push x to back of vector
  nBuffer.push_back(x);
  // Update size of vector
  nSize++;
}
//  Should dequeue an int16_t value and adjust the circular buffer accordingly
int16_t CircularBuffer::dequeue() {
  try {
    if (isEmpty())
      throw std::runtime_error("dequeue: can't dequeue an empty ring\n");
  }catch(const std::runtime_error& err)  {
      printf("Error! dequeue: can't dequeue an empty ring\n");
      throw err;
  }
  // Set front of buffer
  nFront = nBuffer.front();
  // Delete front element
  nBuffer.erase(nBuffer.begin());
  nSize--;
  return nFront;
}
//  Return the current element at the front of the circular buffer
int16_t CircularBuffer::peek() {
  try {
    if (isEmpty())
      throw std::runtime_error("peek: can't peek from an empty buffer");
  }catch(const std::runtime_error& err) {
      printf("Error! peek: can't peek from an empty buffer\n");
      throw err;
  }
  nFront = nBuffer.front();
  return nFront;
}
//  Empty circular buffer and return true
/*
void CircularBuffer::empty() {
  nFirst = 0;
  nBack = 0;
  nSize = 0;
}*/

#include <iostream>
#include <string>
#include <sstream>
#include "FibLFSR.h"

FibLFSR::FibLFSR(std::string seed) {
  _seed = seed;
  l_bit = seed[0];
}

int FibLFSR::step() {
  int curr_bit = l_bit ^ _seed[2];  //  position 13	
  curr_bit = curr_bit ^ _seed[3];  //  position 12
  curr_bit = curr_bit ^ _seed[5];  //  position 10
  std::ostringstream ostring;   // Using string streams to append the XOR result
  for(std::string::size_type i = 0; (unsigned)i < _seed.length() - 1; i++)	//  Shift string to left and overwite leftmost bit
	  ostring << _seed[i + 1];;
  ostring << curr_bit;		//  Concatenate xor result
  _seed = ostring.str();  //  Save new string to  ostring.str() converts a string stream
  return curr_bit;			//  Return xor result
} 
int FibLFSR::generate(int k) {
	int ret_bit = 0;
	for (int i = 0; i < k; i++)			//  Uses arithmetic to convert step() return value from base 2 to 10
		ret_bit = ret_bit*2 + step();
	return ret_bit;
}

int transform(sf::Image& image, FibLFSR* bits) {
	int color = bits->generate(5);
	return color;
}

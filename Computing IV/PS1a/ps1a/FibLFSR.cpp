//Ethan Sourn
#include <iostream>
#include "FibLFSR.h"
#include <string>

FibLFSR::FibLFSR(std::string seed)
{
  _seed = seed;  
  l_bit = _seed[0];
}

int FibLFSR::step()
{	
  int curr_bit = l_bit ^ _seed[2];  //  position 13	
  curr_bit = curr_bit ^ _seed[3];  //  position 12
  curr_bit = curr_bit ^ _seed[5];  //  position 10

  _seed.erase(0,1);  //erases leftmost bit
  l_bit = _seed[0];  //resets l_bit back
	
  return curr_bit;  //returns rightmost bit
} 
int FibLFSR::generate(int k)
{
  int ret_bit = 0;
  for (int i = 0; i < k; i++) {
  ret_bit = ret_bit*2;  //  each bit extracted is doubled 
  //std::cout << ret_bit << " ";
  ret_bit += step();  //  and added to the return val of step()
  }
  return ret_bit;
}
std::ostream& operator << (std::ostream &out, const FibLFSR &object)
{
  out << object._seed << " " << object.r_bit << std::endl;
  return out;
}

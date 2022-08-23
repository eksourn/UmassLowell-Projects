//Ethan Sourn
#ifndef FibLFSR_H
#define FibLFSR_H

#include <string>
class FibLFSR {
public:
	//Constructors
	FibLFSR(std::string seed);
	//Functions
	int step(); 
	int generate(int k);
	//Overloaded << function
	friend std::ostream& operator << (std::ostream &out, const FibLFSR &object);
private:
	std::string _seed;
	int l_bit;
	int r_bit;
	int output;
};


#endif 

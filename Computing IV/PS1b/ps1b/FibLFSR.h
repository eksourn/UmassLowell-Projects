#ifndef FibLFSR_H
#define FibLFSR_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class FibLFSR {
public:
	//Constructors
	FibLFSR(std::string seed);
	//Functions
	int step(); 
	int generate(int k);
private:
	std::string _seed;
	int l_bit;
};
int transform(sf::Image& image, FibLFSR* bits);

#endif

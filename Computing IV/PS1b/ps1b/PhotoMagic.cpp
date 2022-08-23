//  Ethan Sourn
//  Starter code from pixels.cpp
#include <iostream>
#include "FibLFSR.h"

int main(int argc, char *argv[]) {
					
	sf::Image image, image2;
  //  File = > Image
	if (!image.loadFromFile(argv[1]))
		return -1;
	if (!image2.loadFromFile(argv[1]))
		return -1;
	//  Setting object with content of seed
	std::string seed = argv[3];
  //  Creating FibLFSR object
	FibLFSR _s(seed);
	sf::Vector2u size = image.getSize();
	sf::RenderWindow window(sf::VideoMode(size.x, size.y), "Source");
	sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Encrypted");
	 sf::Color p;
   // create random encoded image
   for (unsigned int x = 0; x < size.x; x++) {
     for (unsigned int y = 0; y < size.y; y++) {
       p = image.getPixel(x, y);
       p.r = p.r ^ transform(image, &_s);
       p.g = p.g ^ transform(image, &_s);
       p.b = p.b ^ transform(image, &_s);
       image2.setPixel(x, y, p); //  Assign new pixel values to image 2
     }
   }
	//  Images = > Textures
	sf::Texture texture, texture2;
	texture.loadFromImage(image);
	texture2.loadFromImage(image2);
	//  Textures = > Sprites
	sf::Sprite sprite, sprite2;
	sprite.setTexture(texture);
	sprite2.setTexture(texture2);
  //  Main Loop for SFML
	while (window.isOpen() && window2.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}
		while (window2.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window2.close();
		}
		//1st window
		window.clear();
		window.draw(sprite);
		window.display();
		//2nd window
		window2.clear();
		window2.draw(sprite2);
		window2.display();
	}
	if (!image2.saveToFile("output-file.png"))
		return -1;
	return 0;
}


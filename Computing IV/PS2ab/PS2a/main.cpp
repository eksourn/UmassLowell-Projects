// Ethan Sourn
#include "nbody.h"

int main(int argc, char* argv[]) {
  int N;           //  num of planets/particles
  double R;        //  Radius of universe
  //Input redirection with cin
  std::cin >> N;
  std::cin >> R;
  std::cout << N  << " and " << R;
  //Vector of object class declaration
  std::vector<CelestialBody> cbody_obj;
  //Reserve space of size N on vector
  cbody_obj.reserve(N);		
  
  for (int i = 0; i < N; i++) {	
    //  On each loop create a new default object
   	CelestialBody* c_body = new CelestialBody();     
    //  Read input from file through overloaded >> operator
   	std::cin >> *c_body;       
    //  Set radius to private variable and change position in window
    c_body->setRadius(R);
		c_body->position();        
    //  Push back objects onto vector
    cbody_obj.push_back(*c_body);
}  
	//  Load a background image
	sf::Image background;
	if (!background.loadFromFile("background.png")) {
	  std::cout << "Error loading background image!\n";
    return -1;
  }
	//  Creating texture from image to sprite
	sf::Texture bg_text;
	bg_text.loadFromImage(background);
	sf::Sprite bg_sprite;
	bg_sprite.setTexture(bg_text);
	//  Creating window
	sf::RenderWindow window(sf::VideoMode(1340, 520), "NBody");
	//  Display loop
	while (window.isOpen()) {
    sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
  }
  window.clear();
  //  Display background sprite
  window.draw(bg_sprite);
  //  Display object sprites in vector
  std::vector<CelestialBody>::iterator iter;
  for (iter = cbody_obj.begin(); iter != cbody_obj.end(); iter++)
    window.draw(*iter);
		window.display();
  }
	return 0;
}

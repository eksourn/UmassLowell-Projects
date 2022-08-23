// Ethan Sourn
#include "nbody.h"
int main(int argc, char* argv[]) {
/********* Bg Image, Music, and Text ****************/
  //  Loading background image
	sf::Image background;
	if (!background.loadFromFile("background.png")) {
		std::cout << "Error loading background image!\n";
	    return -1;
  }
  //  Loading sound file
 	sf::SoundBuffer bg_music;
 	if (!bg_music.loadFromFile("2001.wav"))
 	  return -1;
  //  Playing music
	sf::Sound sound;
	sound.setBuffer(bg_music);
	sound.play();
	//  Creating texture from image
	sf::Texture bg_text;	
	bg_text.loadFromImage(background);
	//  Creating sprite from texture
	sf::Sprite bg_sprite;
	bg_sprite.setTexture(bg_text);
  //  Setting Font
  sf::Font font;
  if (!font.loadFromFile("Roboto-Regular.ttf")) {
    std::cout << "Error loading font!\n";
    return -1;
  }
  //  Setting text for time
  sf::Text text("0.0", font);
 /********* Celestial body creation ****************/
 //Read two double command-line arguments T and deltaT
  //  Read two double command-line arguments T and deltaT
 	std::string T = argv[1];
 	std::string deltaT = argv[2];
  //  Convert from string to double
 	double time_limit = std::stod(T);
 	double dT = std::stod(deltaT);	
 	double time_elapsed = 0;
 	//  Creating vector of type class CelestialBody
 	std::vector<CelestialBody> cbody_obj;
 	//  Passing into object A
 	Universe MW(cbody_obj);   	
	//  Creating window
	sf::RenderWindow window(sf::VideoMode(1366, 768), "NBody");
	//  Declare iterators for traversing vector 
	std::vector<CelestialBody>::iterator iter, obj_x, obj_y;
/********* SFML Loop ****************/
  window.setFramerateLimit(60);
 	while (window.isOpen()) {
 	  sf::Event event;
   	while (window.pollEvent(event)) {
   	  if (event.type == sf::Event::Closed)
	    	window.close();
    }
 	  window.clear();
   	//  Display background sprite
   	window.draw(bg_sprite);
   	//  Temp variables
   	double curr_fX, curr_fY; 
   	//  Get first CelestialBody in vector
   	obj_x = cbody_obj.begin();    
   	//  Reset force for each loop (per planet)
   	for (int j = 0; j < 5; j++) {
   	  obj_y = cbody_obj.begin();
   	  curr_fX = 0;
   	  curr_fY = 0;
   	  //  Calculate and update pairwise forces
   	  for (int k = 0; k < 5; k++) {
  		  if (j != k) {
    		  curr_fX = curr_fX + find_fX(*obj_x, *obj_y);
      		curr_fY = curr_fY + find_fY(*obj_x, *obj_y);
    		}
    		obj_y++;
   	  }
    }  
   	obj_x++;
   	//  Display objects and update position
   	for (iter = cbody_obj.begin(); iter != cbody_obj.end(); iter++) {
   	  window.draw(*iter);
	    iter->step(dT);
    	iter->position();
   	}
    //  Exit sim if limit is reached
    time_elapsed += dT;
    if (time_elapsed > time_limit)
      window.close();
    //  Update timer
    std::stringstream ss;
    ss << time_elapsed;
    text.setString(ss.str());
    //  Draw background image
    window.draw(bg_sprite);
    //  Draw current time
    window.draw(text);
   	window.display();
   	}
   	//  Displaying final values of the universe
   	for (iter = cbody_obj.begin(); iter != cbody_obj.end(); iter++)
   	  std::cout << (*iter) << std::endl;
   	return 0;
}

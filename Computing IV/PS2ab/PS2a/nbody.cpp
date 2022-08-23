//  Ethan Sourn
#include "nbody.h"

Universe::Universe(std::vector<CelestialBody> &vect) {
  int N;  //  N = num of planets/particles
  double R;  //  R = radius of universe constant
  //  Input redirection with cin
  std::cin >> N;
  std::cin >> R;
  //  Reserving space on vector of size N
  vect.reserve(N);		
 	for (int i = 0; i < N; i++) {	
  //  On each loop allocate a new object
  CelestialBody* c_body = new CelestialBody();       
  //  Read parameters through overloaded >> operator
 	std::cin >> *c_body;      
  //  Update class member radius
  c_body->setRadius(R);
  c_body->position();        
  //  Push back objects onto vector
  vect.push_back(*c_body);
	}
}
CelestialBody::CelestialBody(double pX, double pY, double nMass, double vX, double vY, std::string name) {
	//  Setting private variables
	posX = pX;
	posY = pY;
	mass = nMass;
	velocX = vX;
	velocY = vY;	
	//  File => Image
	sf::Image input_image;
	if (!input_image.loadFromFile(name)) {
		std::cout << "Failed to load image from constructor!\n";
		exit(-1);
	}
	class_image = input_image;
	sf::Texture input_text;
	input_text.loadFromImage(input_image);
	//  Image => Texture
	class_texture = input_text;
  //  Texture => Sprite
	sf::Sprite input_sprite;
	input_sprite.setTexture(input_text);
	class_sprite = input_sprite;
}
void CelestialBody::position() {
  //  Position of sprites = (R / x) * (window size / 2) + (window / 2) for both x and y
  posX = (posX / radius) * (1340 / 2) + 670;
  posY = (posY / radius) * (520 / 2) + 260;
  //  Update sprite positions
  class_sprite.setPosition(sf::Vector2f(posX, posY));
}
void CelestialBody::setRadius(double r) {
  radius = r;
}
void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(class_sprite);
}
std::istream& operator >> (std::istream &in, CelestialBody &obj) {
  //  Read file parameters
  in >> obj.posX;
  in >> obj.posY;
  in >> obj.mass;
  in >> obj.velocX;
  in >> obj.velocY;
  in >> obj.image_name;
  if (!obj.class_image.loadFromFile(obj.image_name)) {
    std::cout << "Failed to load image from >> function!\n";
		exit(-1);
  }
  //  Repeat multi-arg constructor operations
  obj.class_texture.loadFromImage(obj.class_image);
  obj.class_sprite.setTexture(obj.class_texture);
  obj.class_sprite.setPosition(sf::Vector2f(obj.posX, obj.posY));
  return in;
}
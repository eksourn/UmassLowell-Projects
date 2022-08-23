//  Ethan Sourn
#include "nbody.h"
Universe::Universe(std::vector<CelestialBody> &vect) {
	int N; 
	double R;          
	std::cin >> N;		
	std::cin >> R;   
  vect.reserve(N);
	for (int i = 0; i < N; i++) {	
	  //CelestialBody *c_body = new CelestialBody();  
    std::shared_ptr<CelestialBody> c_body(new CelestialBody());
    //  Read input from file through overloaded >> operator
    std::cin >> *c_body;       
   	//  Set radius to private variable and change position in window
   	c_body->setRadius(R);
 		c_body->position();      
  	//  Push back objects onto vector
  	vect.push_back(*c_body);
	}
}
CelestialBody::CelestialBody(double pX, double pY, double nMass, double vX, double vY, std::string name) {
	//  Setting private variables = arguments for member fctn access
	posX = pX;
	posY = pY;
	mass = nMass;
	velocX = vX;
	velocY = vY;
	//  Loading and creating sprite from input image
	sf::Image input_image;
	if (!input_image.loadFromFile(name)) {
		std::cout << "Failed to load image from constructor!\n";
		exit(-1);
	}
  class_image = input_image;
	sf::Texture input_text;
	input_text.loadFromImage(input_image);	
	//  Set texture
	class_texture = input_text;
	sf::Sprite input_sprite;
	input_sprite.setTexture(input_text);
	class_sprite = input_sprite;
}
void CelestialBody::position() {
  //  Position: (radius / x) * (window size / 2) + window/2 for both x and y
 	posX = (posX / radius) * (2000 / 2) + (2000 / 2);
 	posY = (posY / radius) * (2000 / 2) + (2000 / 2);
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
 	in >> obj.velocX;
 	in >> obj.velocY;
 	in >> obj.mass;
 	in >> obj.image_name;  
 	//  Check if image loads properly
 	if (!obj.class_image.loadFromFile(obj.image_name)) {
 	  std::cout << "Failed to load image from >> function!\n";
	  exit(-1);
	}
	//  Repeat multi-arg constructor operations
	obj.class_texture.loadFromImage(obj.class_image);
	obj.class_sprite.setTexture(obj.class_texture); 
 	obj.class_sprite.setPosition(sf::Vector2f(obj.posX, obj.posY));
 	//  Debugging
 	/*std::cout << "\nObj posX: " << obj.posX << std::endl;
 	std::cout << "Obj posY: " << obj.posY << std::endl;
 	std::cout << "Obj velocX: " << obj.velocX << std::endl;
 	std::cout << "Obj velocY: " << obj.velocY << std::endl;
 	std::cout << "Obj mass: " << obj.mass << std::endl;
 	std::cout << "Obj filename: " << obj.image_name << std::endl << std::endl;*/
	return in;
}
double find_fX(CelestialBody &obj, CelestialBody &obj2) {
  //  Formula: r = sqrt(dx^2 + dy^2)
 	double deltaX, deltaY, r;
 	deltaX = obj2.posX - obj.posX;
 	deltaY = obj2.posY - obj.posY;
 	r = sqrt(pow(deltaX, 2.0) + pow(deltaY, 2.0));
 	//  Formula: F = (G * M1 * M2) / r^2
 	double net_F;
 	net_F = (G * obj.mass * obj2.mass) / (r * r);
 	//  Formula: Fx = F * (dx / r)
 	double _forceX;
 	_forceX = net_F * (deltaX / r);
 	//  Update x-component 
 	obj.set_fX(_forceX);
 	//  Debugging 
  /*std::cout << "Object: " << obj.image_name << std::endl;
  std::cout << "Object2: " << obj2.image_name << std::endl;
 	std::cout << "Obj dx: " << deltaX << std::endl;
 	std::cout << "Obj dy: " << deltaY << std::endl;
 	std::cout << "Obj fX: " << _forceX << std::endl;
 	std::cout << "Obj mass: " << obj.mass << std::endl;
 	std::cout << "Obj2 mass: " << obj2.mass << std::endl;
 	std::cout << "Obj net force " << net_F << std::endl;
 	std::cout << "G: " << G << std::endl << std::endl;*/
	return _forceX;
}
double find_fY(CelestialBody &obj, CelestialBody &obj2) {
  //  Formula: r = sqrt(dx^2 + dy^2)
 	double deltaX, deltaY, r;
 	deltaX = obj2.posX - obj.posX;
 	deltaY = obj2.posY - obj.posY;
 	r = sqrt(pow(deltaX, 2.0) + pow(deltaY, 2.0));
 	//  Formula: F = (G * M1 * M2) / r^2
 	double net_F;
 	net_F = (G * obj.mass * obj2.mass) / (r * r);
 	//  Formula: Fy = F * (dy / r)
 	double _forceY;
 	_forceY = net_F * (deltaY / r);
 	//  Update y-component
 	obj.set_fY(_forceY);
  //  Debugging  
 	/*std::cout << "Object: " << obj.image_name << std::endl;
 	std::cout << "Object2: " << obj2.image_name << std::endl;
 	std::cout << "Obj dx: " << deltaX << std::endl;
 	std::cout << "Obj dy: " << deltaY << std::endl;
 	std::cout << "Obj fY: " << _forceY << std::endl;
 	std::cout << "Obj mass: " << obj.mass << std::endl;
 	std::cout << "Obj2 mass: " << obj2.mass << std::endl;
 	std::cout << "Obj net force " << net_F << std::endl;
 	std::cout << "G: " << G << std::endl << std::endl;*/
 	return _forceY;
}

void CelestialBody::step(double _seconds) {
 	//  Formula: ax = Fx / m, ay = Fy / m
 	aX = forceX / mass;
 	aY = forceY / mass;
 	//  Formula: (vx + dt ax, vy + dt ay)
 	velocX = velocX + (aX * _seconds);
 	velocY = velocY + (aY * _seconds);
 	//  Formula: (px + dt vx, py + dt vy)
 	posX = posX + (velocX * _seconds);
 	posY = posY + (velocY * _seconds);
 	//Debugging
 	/*std::cout << "Time: " << _seconds << std::endl;
 	std::cout << "aX: " << aX << std::endl;
 	std::cout << "aY: " << aY << std::endl;
 	std::cout << "New velocX: " << velocX << std::endl;
 	std::cout << "New velocY: " << velocY << std::endl;
 	std::cout << "New posX: " << posX << std::endl;
 	std::cout << "New posY: " << posY << std::endl;*/
}
 std::ostream &operator<<(std::ostream &out, CelestialBody &obj) {
  //  Printing final state of the universe
  out << "Celestial Body name: " << obj.image_name << std::endl;
  out << "Mass: " << obj.mass << std::endl; 
  out << "Force x: " << obj.forceX << std::endl;
  out << "Force y: " << obj.forceY << std::endl;
  out << "Velocity x: " << obj.velocX << std::endl;
  out << "Velocity y: " << obj.velocY << std::endl;
  out << "Acceleration x: " << obj.aX << std::endl;
  out << "Acceleration y: " << obj.aY << std::endl;
  out << "Position x: " << obj.posX << std::endl;
  out << "Position y: " << obj.posY << std::endl;
  return out; 
}
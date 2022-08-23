//  Ethan Sourn
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <sstream>
#include <memory>

//  Gravitational constant
const float G = 0.00000000000667;
class CelestialBody : public sf::Drawable {
public:
  //  Default Constructor
  CelestialBody() : posX(0), posY(0), mass(0), velocX(0), velocY(0), image_name("no file") {}
  //  Parameterized Constructor
  CelestialBody(double pX, double pY, double nMass, double vX, double vY, std::string name);
  //  Overloaded >> operator  
  friend std::istream &operator>>(std::istream &in, CelestialBody &obj);
  //  Overload << operator
  friend std::ostream &operator<<(std::ostream &out, CelestialBody &obj);
  //  Overload << operator
  //  Set universe radius
  void setRadius(double r);
  //  Set position of planets and stars
  void position();
  //  Mutators
  void set_fX(double _fX) { forceX = _fX; }
  void set_fY(double _fY) { forceY = _fY; }
  //  Finds x-component of net force and y-component
  friend double find_fX(CelestialBody &obj, CelestialBody &obj2);
  friend double find_fY(CelestialBody &obj, CelestialBody &obj2);
  void step(double _seconds);
private:
  //  Allow class universe access to CelestialBody members
  friend class Universe;
  //  Distance between planets and r for calculation respectively
  double radius, r, aX, aY;
	//  Planet parameters
  double posX, posY, mass, velocX, velocY, netForce, forceX, forceY;
  std::string image_name;
  //  Sf objects
	sf::Sprite class_sprite;
  sf::Image class_image;
  sf::Texture class_texture;
  //  Virtual draw 
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
class Universe {
public:
  Universe(std::vector<CelestialBody> &vect);
};

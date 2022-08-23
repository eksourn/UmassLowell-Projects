//  Ethan Sourn
#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>

class CelestialBody : public sf::Drawable {
public:
  //  Default Constructor
  CelestialBody() : posX(0), posY(0), mass(0), velocX(0), velocY(0), image_name("no file") {}
  //  Parameterized Constructor
  CelestialBody(double pX, double pY, double nMass, double vX, double vY, std::string name);
  //  Overloaded >> operator  
  friend std::istream &operator>>(std::istream &in, CelestialBody &obj);
  //  Set universe radius
  void setRadius(double r);
  //  Set position of planets and stars
  void position();
private:
  //  Universe constant
  double radius;
	//  Planet parameters
  double posX, posY, mass, velocX, velocY;
  std::string image_name;
  //  Sf objects
	sf::Sprite class_sprite;
  sf::Image class_image;
  sf::Texture class_texture;
  //  Virtual draw from SFML
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
class Universe {
public:
  Universe(std::vector<CelestialBody> &vect);
};
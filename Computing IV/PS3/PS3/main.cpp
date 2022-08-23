//  Copyright 2021 Ethan Sourn
#include <SFML/System.hpp>
#include "ED.h"

int main(int argc, char* argv[]) {
  //  Variables for execution time
  sf::Clock clock;
  sf::Time t;
  std::string dna1;
  std::string dna2;
  //  Read from command line
  std::cin >> dna1;
  std::cin >> dna2;
  //  Accept strings and allocate data
  ED seq(dna1, dna2);
  //  Get optimal distance cell[0][0]
  int editDistance = seq.OptDistance();
  std:: cout << "Edit distance = " << editDistance << "\n";
  std::string printStr = seq.Alignment();
  std::cout << printStr;
  //  Capture running time
  t = clock.getElapsedTime();
  std::cout << "Execution time is " << t.asSeconds() << " seconds\n";
  return 0;
}

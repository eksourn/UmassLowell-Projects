/*
  Copyright 2015 Fred Martin, 
  Y. Rykalova, 2020
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>

#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "/usr/cs/undergrad/2021/esourn/COMPIV/PS4b/CircularBuffer.h"
#include "/usr/cs/undergrad/2021/esourn/COMPIV/PS4b/StringSound.h"

#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100

std::vector<sf::Int16> makeSamples(StringSound &gs) {
  std::vector<sf::Int16> samples;

  gs.pluck();
  int duration = 8;  // seconds
  int i;
  for (i= 0; i < SAMPLES_PER_SEC * duration; i++) {
    gs.tic();
    samples.push_back(gs.sample());
  }

  return samples;
}

int main() {
  sf::RenderWindow window(sf::VideoMode(300, 200), "SFML String Sound");
  sf::Event event;
  double freq = CONCERT_A;
  std::vector<sf::Int16> sample;
  //  Vectors
  std::vector<std::vector<sf::Int16>> samples(37);
  std::vector<sf::SoundBuffer> buffers(37);
  std::vector<sf::Sound> sounds(37);
  //  Freq -> Guitar Str-> vector<int16> -> soundBuffer -> Sound for each key
  for (int i = 0; i < 37; i++) {
    //  Create string sound
    StringSound ss = StringSound(freq);
    //  Create samples from gs and save into vector
    sample = makeSamples(ss);
    samples[i] = sample;
    //  Load into buffer
    if (!buffers[i].loadFromSamples(&samples[i][0],
     samples[i].size(), 2, SAMPLES_PER_SEC))
      printf("Error!?\n");
    //  Create sounds from buffer
    sounds[i].setBuffer(buffers[i]);
    //  Update freq
    freq = CONCERT_A * pow(2, 3.0/12.0);
  }
  //  37 keys to represent keyboard from lowest to highest note
  std::string keyboard = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128) {
    //  Convert to char
    char key_pressed = static_cast<char>(event.text.unicode);
    //  Loop and check if key is pressed.. if so play corresponding key
    for (int i = 0; i <= 37; i++) {
      if (key_pressed == keyboard[i]) {
        printf("Key played: %c\n", keyboard[i]);
          sounds[i].play();
      }
    }
    }
      }
      window.clear();
      window.display();
    }
  }
  return 0;
}

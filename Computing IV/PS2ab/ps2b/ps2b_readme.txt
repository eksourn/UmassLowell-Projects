/**********************************************************************
 *  N-Body Simulation ps2b-readme.txt template
 **********************************************************************/

Name: Ethan  Sourn

Hours to complete assignment: a lot
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
For this assignment we were to elaborate on PS2A and extend the 
simulation. We were to read from a text file a set of values that 
would allow us to simulate the inner solar system rotation around the sun.

I got the program to read from stdin and have a timer display on the main
screen. Otherwise the planets appear for a brief second before they fly
off the screen. I also included a sound file but I was told it was 
difficult to get any sound to play on MobaXTerm so i'm not sure if it 
works completely. I also printed the state of the universe at the end
of the simulation, although the values are wrong. 

Updated: Changed makefile to remove NBody and included smart pointers in
nbody.cpp line 11.
/**********************************************************************
 *  If you created your own universe for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/
N/A

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
SFML music: https://www.sfml-dev.org/tutorials/2.5/audio-sounds.php

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
My planets keep flying of the screen. I think my math is wrong and I
spent a lot of time troubleshooting but did not solve it.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
Run with ./NBody  157788000.0 25000.0 < planets.txt
Use make clean to remove .o files.

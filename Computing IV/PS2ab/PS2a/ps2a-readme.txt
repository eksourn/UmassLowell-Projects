/**********************************************************************
 *  N-Body Simulation ps2a-readme.txt template
 **********************************************************************/

Name: Ethan Sourn
Hours to complete assignment: 3
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
For this assignment we needed to read input from a text file and output
them into SFML. The input are parameters for the planets in our inner
solar system. So x and y position, velocity, mass, and respective gifs. 

I created both classes the CelestialBody and Universe. I made my program
read from input direction for the text file and then the overloaded
stream insertion. I followed the outlined steps in the homework pdf and 
I believe I did it all correctly.
  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
I used stl template vector to help instantiate new class objects. 

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
The program begins by reading the data from a txt file. It then reads
the input and reserves space for the vector. On each iteration of the 
loop, a new object is created for each planet/star, then all their
respective data, updates their position, and pushes the new object onto
a vector. 

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

Finally, I created the SFML window and displayed all the 
sprites in the vector.

I did not use smart pointers.
/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
https://stackoverflow.com/questions/8011887/how-can-i-create-multiple-objects-with-for-loop-in-c
http://www.tutorialspoint.com/cplusplus/input_output_operators_overloading.htm
/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
N/A
/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
Run with ./NBody < planets.txt
/**********************************************************************
 *  Linear Feedback Shift Register (part B) ps1b-readme.txt template
 **********************************************************************/

Name: Ethan Sourn
Hours to complete assignment: 2
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
For this assignment we were tasked to use encrpyt and decrypt an png 
image by using the generate function in our FibLFSR code. It will change
the given seed with new values which will in turn change the image's
pixel color value which scrambles/encrypts it. Then with the same seed
and input and output pngs get the original source image. 

I accomplished it and took the screenshots. However, I had to change
my step function b/c it was not working properly.
/**********************************************************************
 *  If you did any implementation for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/
N/A
/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
I used pixels.cpp as starter code.

Used the SFML documentation:
https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Image.php

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
N/A
/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
Run with:
./PhotoMagic input-file.png output-file.png 1011011000110110.
 and then swap the input-file.png and output-file.png and run again.

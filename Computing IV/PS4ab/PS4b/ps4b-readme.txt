/**********************************************************************
 *                                                  
 *  PS3b: StringSound implementation and SFML audio output 
 **********************************************************************/

Name: Ethan Sourn

Hours to complete assignment :  ~7hrs

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I implemented everything but I failed to fully debug my code and get the
window to open b/c of an seemingly easy to fix error which I explained
below. 

I know everything prior to this current assignment is working since I 
tested it with a full suite of BOOST tests (so CircularBuffer implementation)
but currently my StringSound is not working.

/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  
 **********************************************************************/
No I did not.

/**********************************************************************
 *  Did you implement exseptions to check your StringSound 
 *	implementation?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
I did, I implemented an exception in the StringSound(double frequency) 
constructor that simnply checks for a valid frequency. If not it will
throw an std::invalid_argument error.


/**********************************************************************
 *  Did you implement lambda expression?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
No.


/**********************************************************************
 *  Did your code pass cpplint?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
Yes, I ran cpplint through each of my files and made changes accordingly.

/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
N/A


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
For some reason everytime I tried to implemnt my empty function I would
get an error where it can not find my declaration of empty in CircularBuffer
class. I then tried to directly empty the buffer and then I kept running
into an error where my object couldn't access it's own classe's private
variables.

It seemed like a simple fix but for some reason nothing I tried worked.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
Run with ./KSGuitarSim
Clean directory with Make clean 

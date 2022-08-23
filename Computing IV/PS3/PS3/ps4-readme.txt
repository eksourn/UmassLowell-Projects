/**********************************************************************
 *  readme 
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Ethan Sourn

Hours to complete assignment: ~7hrs

/**********************************************************************
 * Explain which approach you decided to use when implementing
 * (either recursive with memoization, recursive without memoization,
 * dynamic programming or Hirschberg?s algorithm). Also describe why
 * you chose this approach and what its pros and cons are.
 **********************************************************************/
I went with dynamic programming Needleman and Wursh method. I chose 
this method because I get to avoid using recursion and this sort of
methodology is intuitive to think through. Breaking up the problem into
sub-problems make solving and debugging easier to some degree.

Some downsides would be the amount of memory usage and slow execution. 
Otherwise like I said above it's straightforward and efficient.
/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input: esourn@cs1:~/COMPIV/PS3$ ./ED < tests/endgaps7.txt

Expected output:

Edit distance = 4
a - 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
- a 2
Execution time is 8.5e-05 seconds

What happened:
It seems to work fine.

/**********************************************************************
 * Look at your computer?s specs in the settings. 
 * How much RAM does your computer have and explain what this means? 
 **********************************************************************/
I have 8gb of RAM which means that I could run all the required text files
including ecoli28284.txt.

/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
If M=N then N^2. A would be an int and b would represent M=N. Largest N 
would be around  

a = 4
b = 2
largest N = 28284

4 * 28284 ^ 2 = 3,199,938,624 ~ 3 GB

/**********************************************************************
 * Run valgrind if you can and attach the output file to your submission. 
 * If you cannot run it, explain why, and list all errors youre seeing. 
 * If you can run it successfully, does the memory usage nearly match that 
 * found in the question above? 
 * Explain why or why not. 
/**********************************************************************
--------------------------------------------------------------------------------
Command:            ./ED
Massif arguments:   (none)
ms_print arguments: massif.out.8541
--------------------------------------------------------------------------------


    GB
3.454^                                                                       :
     |                              @########################################:
     |                            @@@#                                       :
     |                          @@@@@#                                       :
     |                         @@@@@@#                                       :
     |                       @@@@@@@@#                                       :
     |                     @@@@@@@@@@#                                       :
     |                     @@@@@@@@@@#                                       :
     |                   @@@@@@@@@@@@#                                       :
     |                 ::@@@@@@@@@@@@#                                       :
     |               @@::@@@@@@@@@@@@#                                       :
     |              @@@::@@@@@@@@@@@@#                                       :
     |            @@@@@::@@@@@@@@@@@@#                                       :
     |           @@@@@@::@@@@@@@@@@@@#                                       :
     |         @@@@@@@@::@@@@@@@@@@@@#                                       :
     |        @@@@@@@@@::@@@@@@@@@@@@#                                       :
     |      @@@@@@@@@@@::@@@@@@@@@@@@#                                       :
     |     @@@@@@@@@@@@::@@@@@@@@@@@@#                                       :
     |   @@@@@@@@@@@@@@::@@@@@@@@@@@@#                                       :
     |  @@@@@@@@@@@@@@@::@@@@@@@@@@@@#                                       :
   0 +----------------------------------------------------------------------->Gi
     0                                                                   353.8

Number of snapshots: 53
 Detailed snapshots: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 50, 51 (peak)]

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
  0              0                0                0             0            0
  1  2,928,013,767       66,004,504       66,000,374         4,130            0
99.99% (66,000,374B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.

The rest of the tabe becomes garbled I don't know the rest of the table values.
Otherwise the memory usage seems close.

/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt        118              0.416501          39.28
ecoli5000.txt        160              1.61486           156.6
ecoli7000.txt        194              3.12733           219.1
ecoli10000.txt       223              6.39879           625.6
ecoli20000.txt       3135             25.6981           2443
ecoli28284.txt       8394             52.0172           3454

/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730



/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 
b = 2
largest N = 

M=N is the same so b = 2. 1 day of computation is 86400 seconds.
**********************************************************************
 *  Did you use the lambda expression in your assignment? If yes, where 
 * (describe a method or provide a lines numbers)
 **********************************************************************/
No b/c it was extra credit.



**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/
Vector of vectors:
https://www.geeksforgeeks.org/vector-of-vectors-in-c-stl-with-examples/
Video on Needleman-Wunsch Method:
https://www.youtube.com/watch?v=ipp-pNRIp4g

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
N/A


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
Run with ./ED < tests/filename.txt
Remove .o and ED with Make clean

/**********************************************************************
 *  readme.txt template                                                   
 *  PS6 Kronos 
 **********************************************************************/

Name: Ethan Sourn


Hours to complete assignment: ~5 hrs


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I think I completed the project. At the moment I am still a little 
confused on what the output should look like as the description was a
little vauge. Alongside with the log files taking forever to open and not
really understanding what I was looking at. So, there might be some incorrect
data.

I believe my regex functions are working because my loops are working and
printing (what I think) the correct output.

/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/

std::string startup("(.*log.c.166.*)");
std::string date = ("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2}) ");
std::string time = ("([0-9]{2}):([0-9]{2}):([0-9]{2})");

The above three regex detect the startupt statement. It finds
the words "log.c.166 server started" and pulls the appropriate date and 
time.

std::string parse_done("(.*oejs.AbstractConnector:Started SelectChannelConnector.*)");
std::string date = ("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2}) ");
std::string time = ("([0-9]{2}):([0-9]{2}):([0-9]{2})");

Finds a successful boot and pulls the date and time.

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
I at first declared all the variables I think I needed which I pulled
from the sample code given. Then I opened the file and output file.
I looped getline until EOF and created two if statements that checked
my two regex expressions:

  boost::regex boot(date + time + startup);
  boost::regex done(date + time + parse_done);

Then I coded the output format and converted to gregorian date and time
posix stuff. Calculated the time elapsed for successful boots and iterated
the line numbers.

/**********************************************************************
 *  Did you use lambda expression? If yes describe there.
 **********************************************************************/
No I did not.

/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
Lots of help from discord discussion on the UML CS computing iv channel.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I have one cpplint error where regex is an unapproved header.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
Run with ./ps6 kronos/"filename" and the output file will be in the 
kronos directory with extension "rpt".
Clear .o files and ps6 with make clean


//  Copyright 2020 Ethan Sourn
#include <iostream>
#include <fstream>
#include <ostream>
#include <regex>
#include <string>
#include <boost/regex.hpp>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

int main(int argc, char* argv[]) {
  //  Read filename from command line
  if (argc != 2) {
    std::cout << "Incorrect amount of arguments on command line!\n";
    return -1;
  }
  //  Variables
  int line_number = 1;
  std::string s, rs;
  bool status = false;
  boost::posix_time::ptime t, t1;

  //  Strings for regex expressions
  std::string startup("(.*log.c.166.*)");
  std::string parse_done
  ("(.*oejs.AbstractConnector:Started SelectChannelConnector.*)");
  std::string date = ("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2}) ");
  std::string time = ("([0-9]{2}):([0-9]{2}):([0-9]{2})");

  //  Regex expressions
  boost::regex boot(date + time + startup);
  boost::regex done(date + time + parse_done);
  //  Catch matched parts of strings
  boost::smatch sm;

  //  Opening device log to read
  std::string filename = argv[1];
  std::ifstream file(filename.c_str());

  //  Opening output file to write to
  std::ofstream output;
  std::string outFile(filename + ".rpt");
  output.open(outFile.c_str());

  //  file.open(filename);
  if (file.is_open()) {
    // Read until EOF
    while (getline(file, s)) {
      //  Try to find a start boot
      if (boost::regex_search(s, sm, boot)) {
       /* //  Case of finding a start earlier than expected
        if (status) {
          output << "***** Incomplete boot *****\n\n";
        }*/
        //  Gregorian date conversion
        boost::gregorian::date d(boost::gregorian::from_simple_string(sm[0]));
        //  Posix date conversion
        boost::posix_time::ptime tmp(d, boost::
        posix_time::time_duration(std::stoi(sm[4]),
        std::stoi(sm[5]), std::stoi(sm[6])));
        t1 = tmp;
        //  Output format
        output << "Startup on line: " << line_number << "\n";
        output << "Timestamp: " << sm[1] << "-" << sm[2] << "-" << sm[3] << " ";
        output << sm[4] << ":" << sm[5] << ":" << sm[6] << "\n";
        output << "FAILURE" << "\n\n";
        status = true;
      }
      //  Successful boot scenario
      if (boost::regex_search(s, sm, done)) {
        if (status) {
        boost::gregorian::date d(boost::gregorian::from_simple_string(sm[0]));
        boost::posix_time::ptime tmp(d, boost::
        posix_time::time_duration(std::stoi(sm[4]),
        std::stoi(sm[5]), std::stoi(sm[6])));
          t = tmp;
          boost::posix_time::time_duration elapsed = t - t1;
          output << "Startup on line: " << line_number << "\n";
          output << "Timestamp: " << sm[1]
          << "-" << sm[2] << "-" << sm[3] << " ";
          output << sm[4] << ":" << sm[5] << ":" << sm[6] << "\n";
          output << "SUCCESS" << ", duration: " <<
          std::to_string(elapsed.total_milliseconds()) << "ms \n\n";

          //  Reset flag for next loop
          status = false;
        }
      }
      line_number++;
    }
  }
  file.close();
  output.close();
  return 0;
}

// Dr. Rykalova
// test.cpp for PS1a
// updated 1/31/2020

#include <iostream>
#include <string>

#include "FibLFSR.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1); 
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9) == 51);
	
  /* Two additional test cases created
   * The first will ask to generate and simulate 5 steps of the LFSR. */
  FibLFSR l3("0011101100000001");  //  seed taken from pdf from "Extracting multiple bits" section
  BOOST_REQUIRE(l3.generate(5) == 13);


 /* The second will ask to generate and simulate 6 steps of the LFSR.
  * BOOST_REQUIRE will check to see if the 6 bits extracted is equal to 0. */
  FibLFSR l4("1101100001100110 ");
  BOOST_REQUIRE(l4.generate(5) == 14);  //  also taken from pdf section "Extracting multiple bits"

}

/* This test block will continue testing the program
 * with additional seeds. The both tests should always
 * return 0 */
BOOST_AUTO_TEST_CASE(additionalTests) {

  FibLFSR aT("11111111111111111");
  BOOST_REQUIRE(aT.step() == 0);
  BOOST_REQUIRE(aT.step() == 0);
  BOOST_REQUIRE(aT.step() == 0);
  BOOST_REQUIRE(aT.step() == 0);
  BOOST_REQUIRE(aT.step() == 0);
  
  FibLFSR aT2("1010101010101010");
  BOOST_REQUIRE(aT2.generate(2) == 0);
}

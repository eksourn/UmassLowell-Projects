//  Copyright 2021 Ethan Sourn
#include "ED.h"
//  Accept two strings to be compared and allocates any data structure necessary
ED::ED(std::string str, std::string str2) {
  sequence1 = str;
  sequence2 = str2;
  //  Get sizes for MxN matrix
  _M = sequence1.length();
  _N = sequence2.length();
  for (int i = 0; i <= _M; i++) {
    //  Populate container vector with more vectors
    std::vector<int> tmp;
    matrix.push_back(tmp);
    //  Fill w/ 0s
    for (int j = 0; j <= _N; j++) {
      matrix.at(i).push_back(0);
    }
  }
}
//  Returns penalty for aligning chars a and b (0 or 1)
int ED::penalty(char a, char b) {
  if (a == b) {
    return 0;
  } else if (a != b) {
    return 1;
  }
  //  If there is somehow an incorrect value
  return -1;
}
//  Returns the mininum of the three args
int ED::min(int a, int b, int c) {
  int lv = std::min(a, b);
  lv = std::min(lv, c);
  return lv;
}
//  Populates the matrix based on 2 strings and returns cell[0][0]
int ED::OptDistance() {
  //  Fill bottom row since values always double
  for (int i = 0; i <= _M; i++) {
    matrix[i][_N] = 2 * (_M - i);
  }
  //  Fill rightmost side
  for (int i = 0; i <= _N; i++) {
    matrix[_M][i] = 2 * (_N - i);
  }
  int opt1, opt2, opt3;
  //  Opt[i][j] = min {opt[i+1][j+1]+0/1, opt[i+1][j]+2, opt[i][j+1]+2}
  for (int i = _M - 1; i >= 0; i--) {
    for (int j = _N - 1; j >= 0; j--) {
      opt1 = matrix[i+1][j+1] + penalty(sequence1[i], sequence2[j]);
      opt2 = matrix[i+1][j] + 2;
      opt3 = matrix[i][j+1] + 2;
      matrix[i][j] = min(opt1, opt2, opt3);
    }
  }
  //  Return edit distance
  return matrix[0][0];
}
//  Traces the matrix & returns a string that prints the most efficient alignment
std::string ED::Alignment() {
  std::stringstream ss;
  unsigned i = 0, j = 0;
  //  Navigate matrix and calculate the opt for each element
  while(i < matrix.size() - 1 || j < matrix[0].size() - 1) {
    //  Calculate which movement to perform diag, right, or down and print the appropriate row information
    //  Diag
    if ((i < matrix.size() - 1) && (j < matrix[0].size() - 1) && (matrix[i+1][j+1] <= matrix[i+1][j] + 1)  
      && (matrix[i+1][j+1] <= matrix[i][j+1] + 1)) {
      ss << sequence1[i] << " " << sequence2[j] << " " << matrix[i][j] - matrix[i+1][j+1] << '\n';
      i++;
      j++;
    }
    //  Right
    else if(((i < matrix.size() - 1) && (matrix[i+1][j] <= matrix[i][j+1])) || (j == matrix[0].size() - 1)) {
      ss << sequence1[i] << " " << "-" << " " << matrix[i][j] - matrix[i+1][j] << '\n';
      i++;
    }
    //  Down
    else {
      ss << "-" << " " << sequence2[j] << " " << matrix[i][j] - matrix[i][j+1] << '\n';
      j++;
    }
  }
  return ss.str();
}

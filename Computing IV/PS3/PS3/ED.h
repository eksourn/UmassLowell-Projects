//  Copyright 2021 Ethan Sourn
#pragma once
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

class ED {
 public:
  explicit ED(std::string str1, std::string str2);
  static int penalty(char a, char b);
  static int min(int a, int b, int c);
  int OptDistance();
  std::string Alignment();
 private:
  //  Matrix declaration
  std::vector<std::vector<int>> matrix;
  //  Holds Sequences to be compared
  std::string sequence1;
  std::string sequence2;
  //  Sizes of row, column, and total size
  int _N;
  int _M;
  int total;
};

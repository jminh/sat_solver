#include "str_util.h"

#include <iostream>
#include <sstream>

std::vector<std::string> split(const std::string str) {
  std::vector<std::string> strings;
  std::istringstream f(str);

  std::string s;
  while (getline(f, s, ' ')) {
    strings.push_back(s);
  }
  return strings;
}

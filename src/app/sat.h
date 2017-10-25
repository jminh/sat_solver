#ifndef GUARD_sat_h
#define GUARD_sat_h

#include <unordered_map>
#include <vector>
#include <string>

class SAT {
public:
  std::vector<std::string> variables;
  std::unordered_map<std::string, int> variable_table;
  std::vector<std::vector<int>> clause;

public:
  void parse_and_add_clause(std::string line);
};

#endif

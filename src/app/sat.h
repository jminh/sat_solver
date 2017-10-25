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


std::vector<std::vector<std::vector<int>>> setup_watchlist(SAT instance);

bool update_watchlist(const SAT& instance,
                      std::vector<std::vector<std::vector<int>>>& watchlist,
                      int false_literal,
                      const std::vector<int>& assigment,
                      bool verbose);

void solve(const SAT& instance,
           std::vector<std::vector<int>>& solution,
           std::vector<std::vector<std::vector<int>>>& watchlist,
           std::vector<int>& assigment,
           int d,
           bool verbose);

#endif

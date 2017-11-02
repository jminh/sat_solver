#include "sat.h"
#include <iostream>

#define ELPP_STL_LOGGING
#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main() {
  SAT sat;
   LOG(INFO) << "My first info log using default logger";
   LOG(INFO) << "My first info log using default logger";

  sat.parse_and_add_clause("A B ~C");
  sat.parse_and_add_clause("B C");
  sat.parse_and_add_clause("~B");
  sat.parse_and_add_clause("~A C");

  for (auto& vec: sat.clause) {
    for (auto& item : vec) {
        std::cout << item;
        std::cout << ' ';
    }
    std::cout << '\n';
  }


   LOG(INFO) << sat.clause;

  for (auto &kv: sat.variable_table) {
      std::cout << kv.first;
      std::cout << ' ';
      std::cout << kv.second;
      std::cout << '\n';
  }

  auto watchlist = setup_watchlist(sat);
  std::cout << sat.variables.size() << '\n';

  std::vector<int> assigment(sat.variables.size(), -1);

  std::vector<std::vector<int>> solution;

  // solve, solve_iterative
  solve_iterative(sat, solution, watchlist, assigment, 0, false);
  std::cout << "number" ;

  std::cout << solution.size() << "\n";
  for (auto & sol: solution) {
      for (auto &i: sol) {
          std::cout << i;
      }
      std::cout << "\n";
  }
}

#include "sat.h"
#include <iostream>

int main() {
  SAT sat;

  sat.parse_and_add_clause("A B C");
  sat.parse_and_add_clause("~A D");

  for (auto& vec: sat.clause) {
    for (auto& item : vec) {
        std::cout << item;
        std::cout << ' ';
    }
    std::cout << '\n';
  }

  for (auto &kv: sat.variable_table) {
      std::cout << kv.first;
      std::cout << ' ';
      std::cout << kv.second;
      std::cout << '\n';
  }

}

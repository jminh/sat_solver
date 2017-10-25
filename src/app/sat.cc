#include "sat.h"
#include "str_util.h"

#include <iostream>
#include <set>


void SAT::parse_and_add_clause(std::string line) {
  std::vector<int> ret_clause = {};

  for (auto literal: split(line)) {
    int negated = 0;
    if (literal[0] == '~') negated = 1;
    auto variable = literal.substr(negated, literal.size());
    std::cout << variable << '\n';

    if (variable_table.find(variable) == variable_table.end()) {
      variable_table[variable] = variables.size();
      variables.push_back(variable);
    }

    auto encoded_literal = variable_table[variable] << 1 | negated;
    ret_clause.push_back(encoded_literal);
  }

  std::set<int> set_clause(ret_clause.begin(), ret_clause.end());
  std::vector<int> unique_clause(set_clause.begin(), set_clause.end());
  clause.push_back(unique_clause);

}

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

std::vector<std::vector<std::vector<int>>> setup_watchlist(SAT instance){
    const auto watchlist_len = instance.variables.size() * 2;
    std::vector<std::vector<std::vector<int>>> watchlist(watchlist_len);

    for (auto& clause: instance.clause) {
        watchlist[clause[0]].push_back(clause);
    }

    return watchlist;
}

bool update_watchlist(const SAT& instance,
                      std::vector<std::vector<std::vector<int>>>& watchlist,
                      int false_literal,
                      const std::vector<int>& assigment,
                      bool verbose) {
    while (!watchlist[false_literal].empty()) {
        auto clause = watchlist[false_literal][0];

        auto found_alternative = false;
        for (auto alternative :clause) {
            auto v = alternative >> 1;
            auto a = alternative & 1;
            if (assigment[v] == -1 || assigment[v] == a^1) {
                found_alternative = true;
                // del watchlist[false_literal][0]
                //watchlist.erase(watchlist.begin());
                watchlist[false_literal].erase(watchlist[false_literal].begin());

                watchlist[alternative].push_back(clause);
                break;
            }
        }

        if (!found_alternative) {
            if (verbose) {
                // instance
                1;
            }
            return false;
        }
    }
    return true;
}

void solve(const SAT& instance,
           std::vector<std::vector<int>>& solution,
           std::vector<std::vector<std::vector<int>>>& watchlist,
           std::vector<int>& assigment,
           int d,
           bool verbose) {

    if (d == instance.variables.size()) {
        solution.push_back(assigment);
        return;
    }

    std::vector<int> false_true{0, 1};
    for (auto &a : false_true) {
        if (verbose) {
            std::cout << "verbose mode" << "\n";
        }
        assigment[d] = a;


        if (update_watchlist(instance, watchlist, (d<<1|a), assigment, verbose)) {
            solve(instance, solution, watchlist, assigment, d+1, verbose);
        }
    }
    assigment[d] = -1;
}

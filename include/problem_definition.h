#ifndef PROBLEM_DEFINITION_H
#define PROBLEM_DEFINITION_H

#include <string>
#include <vector>

// define Trade as struct
struct Trade {
  int profit;
  int risk;
  int capital;
};

// define Problem Instance as struct
struct ProblemInstance {
  int N;                     // number of trades
  int R_max;                 // maximum of total ris
  int C_max;                 // maximum of total capital
  std::vector<Trade> trades; // list of trades
};

#endif

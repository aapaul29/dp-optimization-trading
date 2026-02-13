#include "utils.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

using namespace std;

ProblemInstance load_instance(const string &filename) {
  ProblemInstance instance;

  ifstream file(filename);
  if (!file.is_open()) {
    throw runtime_error("Error: Could not open file " + filename);
  }

  // Read first line: N R_max C_max
  file >> instance.N >> instance.R_max >> instance.C_max;

  if (file.fail()) {
    throw runtime_error("Error: Invalid header format in " + filename);
  }

  instance.trades.reserve(instance.N);

  // Read trade data
  for (int i = 0; i < instance.N; ++i) {
    Trade trade;
    file >> trade.profit >> trade.risk >> trade.capital;

    if (file.fail()) {
      throw runtime_error("Error: Invalid trade data in " + filename);
    }

    instance.trades.push_back(trade);
  }

  file.close();
  return instance;
}

void print_instance(const ProblemInstance &instance) {
  cout << "Number of trades: " << instance.N << "\n";
  cout << "Risk limit: " << instance.R_max << "\n";
  cout << "Capital limit: " << instance.C_max << "\n\n";

  for (int i = 0; i < instance.N; ++i) {
    const Trade &t = instance.trades[i];
    cout << "Trade " << i << " | Profit: " << t.profit << " | Risk: " << t.risk
         << " | Capital: " << t.capital << "\n";
  }
}
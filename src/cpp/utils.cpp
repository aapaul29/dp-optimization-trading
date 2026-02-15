#include "utils.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

ProblemInstance load_instance(const std::string &filename) {
  ProblemInstance instance;
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Error: Could not open file " + filename);
  }
  file >> instance.N >> instance.R_max >> instance.C_max;

  if (file.fail()) {
    throw std::runtime_error("Error: Invalid header format in file" + filename);
  }
  instance.trades.reverse(instance.N);

  for (int i = 0; i < instance.N; i++) {
    Trade t;
    file >> t.profit >> t.risk >> t.capital;
    if (file.fail()) {
      throw std::runtime_error("Error: Invalid trade data in file" + filename);
    }
    instance.trades.push_back(t);
  }
  file.close();
  return instance;
}
#include "../include/problem_definition.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

// Loads trading data from file
ProblemInstance load_instance(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) throw std::runtime_error("Could not open file: " + filename);

    ProblemInstance inst;
    // Reads header: N, R_max, C_max
    if (!(file >> inst.n >> inst.max_risk >> inst.max_capital)) {
         throw std::runtime_error("Invalid file format");
    }

    for (int i = 0; i < inst.n; ++i) {
        Asset a;
        if (file >> a.profit >> a.risk >> a.capital) {
            inst.assets.push_back(a);
        }
    }
    return inst;
}

void print_instance(const ProblemInstance& instance) {
    std::cout << "Trades: " << instance.n << " | Risk Cap: " << instance.max_risk 
              << " | Capital Cap: " << instance.max_capital << "\n";
}
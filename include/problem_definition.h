#ifndef PROBLEM_DEFINITION_H
#define PROBLEM_DEFINITION_H

#include <vector>
#include <string>

// Structure for trade assets
struct Asset {
    int profit;   // p_i
    int risk;     // r_i
    int capital;  // c_i
};

// Container for the knapsack problem instance
struct ProblemInstance {
    int n;
    int max_risk;    // R_max
    int max_capital; // C_max
    std::vector<Asset> assets;
};

// Utility functions for data handling
ProblemInstance load_instance(const std::string& filename);
void print_instance(const ProblemInstance& instance);

#endif
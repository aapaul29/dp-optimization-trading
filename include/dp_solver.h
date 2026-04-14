#ifndef DP_SOLVER_H
#define DP_SOLVER_H

#include "problem_definition.h"

// Returns max profit using Iterative Bottom-Up DP with Space Optimization
int solve_iterative(const ProblemInstance& instance);

// Returns max profit using Top-Down DP with Memoization
int solve_memoized(const ProblemInstance& instance);

// Returns max profit using a cache-friendly flattened memory layout
int solve_optimized(const ProblemInstance& instance);

#endif
#ifndef DP_SOLVER_H
#define DP_SOLVER_H
#include "problem_definition.h"
//Declare the functions for the three solvers
int iterative_solver(const ProblemInstance&);

int memoized_solver(const ProblemInstance&);

int optimized_solver(const ProblemInstance&);
#endif

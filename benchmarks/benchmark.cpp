#include <iostream>
#include "../include/problem_definition.h"
#include "../include/dp_solver.h"

int main() {
  // Create a sample problem instance
  ProblemInstance instance;
  instance.N = 5;
  instance.R_max = 10;
  instance.C_max = 15;
  instance.trades = {
    {10, 2, 3},
    {15, 3, 5},
    {20, 5, 7},
    {25, 4, 6},
    {30, 6, 8}
  };
  //Solve the problem using the three solvers and print the results
  std::cout << "Iterative Solver: " << iterative_solver(instance) << std::endl;
  std::cout << "Memoized Solver: " << memoized_solver(instance) << std::endl;
  std::cout << "Optimized Solver: " << optimized_solver(instance) << std::endl;
  
  return 0;
}

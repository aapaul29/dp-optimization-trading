#include "../include/problem_definition.h"
#include "../include/dp_solver.h"
#include <iostream>
#include <chrono>

// Benchmarking utility to measure execution time
void run_bench(std::string label, int (*func)(const ProblemInstance&), const ProblemInstance& inst) {
    auto start = std::chrono::high_resolution_clock::now();
    int result = func(inst);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms = end - start;
    std::cout << label << ": " << result << " (Time: " << ms.count() << " ms)\n";
}

int main() {
    try {
        ProblemInstance small = load_instance("data/small_instance.txt");
        print_instance(small);
        run_bench("Iterative", solve_iterative, small);
        run_bench("Memoized ", solve_memoized, small);
        run_bench("Optimized", solve_optimized, small);
    } catch (const std::exception& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
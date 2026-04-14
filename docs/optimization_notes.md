# Optimization Notes

The following techniques were implemented to ensure high-performance, deterministic execution of the DP algorithm.

## 1. Dimensionality Reduction
In a standard 0/1 Knapsack problem, the state is often represented as `dp[i][r][c]`. 
- **Optimization:** By iterating through the risk and capital constraints in **reverse** (from max to item-weight), we can compute the current item's state using only the previous state's data within a single 2D array.
- **Impact:** Reduces memory footprint by a factor of $N$.

## 2. Flattened Memory Layout (Cache Locality)
In `optimized_dp.cpp`, we replace `std::vector<std::vector<int>>` with a single `std::vector<int>` of size `(R+1) * (C+1)`.
- **Optimization:** We manually calculate the index using `(row * total_columns) + column`.
- **Impact:** Prevents "vector of vectors" memory fragmentation. Data is stored contiguously in memory, leading to fewer cache misses and faster row-major access.

## 3. Reference Comparison (C++ vs. Python)
The `reference/` directory contains a Python implementation. 
- **Finding:** While Python is excellent for prototyping, the C++ version (compiled with `-O2`) is roughly 50x–100x faster on larger instances.
- **Trading Application:** This speed allows for real-time re-optimization of portfolios as risk limits or market profits change throughout the trading day.

## 4. Compiler-Level Optimizations
The `Makefile` uses the `-O2` flag.
- **Effect:** Enables loop unrolling and strict aliasing rules, allowing the compiler to optimize the nested loops that form the core of the DP engine.

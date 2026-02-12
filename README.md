# Dynamic Programming Optimization in C++

## Overview

This project implements and benchmarks optimized C++ dynamic programming algorithms for solving capital- and risk-constrained portfolio allocation problems inspired by quantitative trading.

Focus:
- Algorithmic efficiency
- Deterministic performance
- Time–space complexity optimization
- Low-level C++ implementation

---

## Problem

Given trades with:

- Expected profit p_i
- Risk exposure r_i
- Capital requirement c_i

Maximize total expected profit subject to:

- Total risk ≤ R_max
- Total capital ≤ C_max

This is modeled as a multi-dimensional knapsack dynamic programming problem.

---

## Implementations

### Iterative Bottom-Up DP (Primary)

State:

dp[r][c] = maximum profit achievable  
           with risk r and capital c

Time Complexity: O(N · R_max · C_max)  
Space Complexity: O(R_max · C_max)

Optimizations:
- Dimensionality reduction
- Reverse iteration to avoid state overwrite
- Cache-friendly memory layout
- Compiled with -O2

---

### Top-Down DP with Memoization

- Recursive formulation
- Used for comparison
- Demonstrates recursion overhead vs iterative DP

---

## Benchmarking

Includes a Python reference implementation for performance comparison.

Results:
- C++ achieves significant speedup
- Predictable runtime scaling
- Highlights importance of low-level optimization in latency-sensitive systems

---

## Relevance to Trading

- Capital allocation under strict risk limits  
- Deterministic algorithmic execution  
- Performance-critical optimization  

---

## Build

g++ -O2 -std=c++17 src/cpp/optimized_dp.cpp -o dp  
./dp

---

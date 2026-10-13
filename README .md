# Dynamic Programming Optimization in C++

## Overview

Capital- and risk-constrained portfolio allocation via optimized C++ dynamic programming — benchmarked against a Python reference implementation.

**Focus areas:**
- Algorithmic efficiency
- Deterministic performance
- Time–space complexity optimization
- Low-level C++ implementation

---

## Repository Structure

```
.
├── include/           # Header files (.h)
├── src/               # Implementation files (.cpp)
├── reference/         # Python reference implementation
├── benchmarks/        # C++ benchmarking source
├── data/              # Input datasets (small / large instances)
├── docs/              # Analysis and optimization notes
├── build/             # Compiled binaries (generated)
└── README.md
```

---

## Problem Formulation

Given N trades each with expected profit `p_i`, risk exposure `r_i`, and capital requirement `c_i`, maximize total expected profit subject to:

```
maximize    Σ p_i · x_i
subject to  Σ r_i · x_i ≤ R_max
            Σ c_i · x_i ≤ C_max
            x_i ∈ {0, 1}
```

- **Total risk** ≤ `R_max`
- **Total capital** ≤ `C_max`

---

## Implementations

### Iterative Bottom-Up DP (Primary)

| Property | Value |
|---|---|
| Time Complexity | `O(N · R_max · C_max)` |
| Space Complexity | `O(R_max · C_max)` |

Optimizations: dimensionality reduction, reverse iteration, cache-friendly layout.

### Top-Down DP with Memoization

Recursive formulation used for overhead comparison against the iterative approach.

---

## Execution Guide

**Prerequisites:** a C++17 compiler (`g++`) and Python 3. On Windows, `g++` from [MSYS2](https://www.msys2.org/) (UCRT64) works.

Run all commands from the project root. The benchmark loads `data/small_instance.txt` by a relative path, so it fails to find the file if run from another directory.

### 1. Build the Project

Compile all C++ sources with `g++`:

```bash
# Linux / macOS
g++ -std=c++17 -O2 -Iinclude src/*.cpp benchmarks/benchmark.cpp -o build/dp_benchmark

# Windows
g++ -std=c++17 -O2 -static -Iinclude src/*.cpp benchmarks/benchmark.cpp -o build/dp_benchmark.exe
```

> **Windows note:** keep the `-static` flag. Without it, the program can crash at startup with a segmentation fault if another `libstdc++` DLL on your `PATH` gets loaded instead of the one that matches your compiler.

### 2. Run C++ Benchmarks

Execute the compiled binary:

```bash
# Linux / macOS
./build/dp_benchmark

# Windows PowerShell
.\build\dp_benchmark.exe
```

Expected output (timings vary):

```
Trades: 5 | Risk Cap: 10 | Capital Cap: 10
Iterative: 13 (Time: 0.0257 ms)
Memoized : 13 (Time: 0.0174 ms)
Optimized: 13 (Time: 0.0026 ms)
```

### 3. Run Python Reference

Verify results against the Python implementation:

```bash
# Linux / macOS
python3 reference/dp_reference.py

# Windows
python reference/dp_reference.py
```

It should print `Python Result: 13`, matching the C++ solvers.

---

## Command Summary

| Action | Command |
|---|---|
| Build (Linux / macOS) | `g++ -std=c++17 -O2 -Iinclude src/*.cpp benchmarks/benchmark.cpp -o build/dp_benchmark` |
| Build (Windows) | `g++ -std=c++17 -O2 -static -Iinclude src/*.cpp benchmarks/benchmark.cpp -o build/dp_benchmark.exe` |
| Execute C++ | `./build/dp_benchmark` (Windows: `.\build\dp_benchmark.exe`) |
| Execute Python | `python3 reference/dp_reference.py` (Windows: `python`) |

---

## Relevance to Trading

- **Capital allocation** — models real-world capital deployment under strict risk budget constraints.
- **Deterministic execution** — fully deterministic algorithmic logic with no stochastic or runtime variance.
- **Performance-critical** — optimized for latency-sensitive systems using low-level C++ techniques.

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
├── Makefile
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

### 1. Build the Project

Compile all C++ sources using the Makefile:

```bash
make
```

### 2. Run C++ Benchmarks

Execute the compiled binary from the project root:

```bash
# Linux / macOS
./build/dp_benchmark

# Windows PowerShell
.\build\dp_benchmark.exe
```

### 3. Run Python Reference

Verify results against the Python implementation:

```bash
python3 reference/dp_reference.py
```

---

## Command Summary

| Action | Command |
|---|---|
| Clean old files | `make clean` |
| Build project | `make` |
| Execute C++ | `./build/dp_benchmark` |
| Execute Python | `python3 reference/dp_reference.py` |

---

## Relevance to Trading

- **Capital allocation** — models real-world capital deployment under strict risk budget constraints.
- **Deterministic execution** — fully deterministic algorithmic logic with no stochastic or runtime variance.
- **Performance-critical** — optimized for latency-sensitive systems using low-level C++ techniques.

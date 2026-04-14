# Complexity Analysis

This project solves a **Multi-Dimensional Knapsack Problem** (2D) where we optimize for profit subject to Risk and Capital constraints.

## Theoretical Complexity

Given:
- $N$: Number of assets/trades
- $R_{max}$: Maximum risk limit
- $C_{max}$: Maximum capital limit

### 1. Time Complexity
The time complexity for all implemented algorithms (Iterative, Memoized, and Optimized) is:
$$O(N \times R_{max} \times C_{max})$$

**Reasoning:**
We iterate through each of the $N$ items exactly once. For each item, we perform a nested traversal of the 2D state space defined by $R$ and $C$.

### 2. Space Complexity

#### Iterative & Optimized DP
By utilizing **dimensionality reduction**, we reduce the space complexity to:
$$O(R_{max} \times C_{max})$$
Unlike the naive approach which requires $O(N \times R \times C)$, we only store the results of the previous "row" of items to calculate the current one.

#### Memoized DP
The recursive approach requires storing all states to avoid redundant calculations:
$$O(N \times R_{max} \times C_{max})$$
Additionally, this method incurs $O(N)$ auxiliary space on the call stack due to recursion depth.

---

## Performance in Trading Context
In low-latency environments, $O(R \times C)$ space is significantly more cache-friendly. The optimized C++ version minimizes pointer chasing, ensuring that the 2D grid fits as much as possible within the CPU's L2/L3 cache levels.

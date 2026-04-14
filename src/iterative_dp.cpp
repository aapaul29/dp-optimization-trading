#include "../include/dp_solver.h"
#include <vector>
#include <algorithm>

int solve_iterative(const ProblemInstance& inst) {
    // Space Complexity: O(R_max * C_max)
    std::vector<std::vector<int>> dp(inst.max_risk + 1, std::vector<int>(inst.max_capital + 1, 0));

    for (const auto& asset : inst.assets) {
        // Reverse iteration to avoid using the same trade twice
        for (int r = inst.max_risk; r >= asset.risk; --r) {
            for (int c = inst.max_capital; c >= asset.capital; --c) {
                dp[r][c] = std::max(dp[r][c], dp[r - asset.risk][c - asset.capital] + asset.profit);
            }
        }
    }
    return dp[inst.max_risk][inst.max_capital];
}

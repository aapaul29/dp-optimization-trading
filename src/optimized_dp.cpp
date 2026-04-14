#include "../include/dp_solver.h"
#include <vector>

int solve_optimized(const ProblemInstance& inst) {
    int rows = inst.max_risk + 1;
    int cols = inst.max_capital + 1;
    // Cache-friendly memory layout using a flattened array
    std::vector<int> dp(rows * cols, 0);

    for (const auto& asset : inst.assets) {
        int ar = asset.risk;
        int ac = asset.capital;
        int ap = asset.profit;

        for (int r = inst.max_risk; r >= ar; --r) {
            int row_offset = r * cols;
            int prev_row_offset = (r - ar) * cols;
            for (int c = inst.max_capital; c >= ac; --c) {
                int score = dp[prev_row_offset + (c - ac)] + ap;
                if (score > dp[row_offset + c]) {
                    dp[row_offset + c] = score;
                }
            }
        }
    }
    return dp.back();
}

#include "../include/dp_solver.h"
#include <vector>
#include <algorithm>

int solve_rec(int i, int r, int c, const ProblemInstance& inst, std::vector<std::vector<std::vector<int>>>& memo) {
    if (i == inst.n || (r == 0 && c == 0)) return 0;
    if (memo[i][r][c] != -1) return memo[i][r][c];

    // Option: Skip current trade
    int res = solve_rec(i + 1, r, c, inst, memo);

    // Option: Execute trade if limits allow
    if (inst.assets[i].risk <= r && inst.assets[i].capital <= c) {
        res = std::max(res, inst.assets[i].profit + 
                       solve_rec(i + 1, r - inst.assets[i].risk, c - inst.assets[i].capital, inst, memo));
    }
    return memo[i][r][c] = res;
}

int solve_memoized(const ProblemInstance& inst) {
    // Recursive formulation used for comparison
    std::vector<std::vector<std::vector<int>>> memo(
        inst.n, std::vector<std::vector<int>>(inst.max_risk + 1, std::vector<int>(inst.max_capital + 1, -1))
    );
    return solve_rec(0, inst.max_risk, inst.max_capital, inst, memo);
}

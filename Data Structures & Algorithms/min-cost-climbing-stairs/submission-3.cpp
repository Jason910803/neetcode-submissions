class Solution {
private:
    int solve(const vector<int>& cost, vector<int>& memo, int n) {
        if (n >= cost.size()) return 0;

        if (memo[n] != -1) return memo[n];

        return memo[n] = cost[n] + min(solve(cost, memo, n + 1), solve(cost, memo, n + 2));
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size(), -1);
        solve(cost, memo, 0);
        return min(memo[0], memo[1]);
    }
};

class Solution {
private:
    int solve(const vector<int>& cost, vector<int>& memo, int n) {
        if (n >= cost.size()) return 0;

        if (memo[n] != -1) return memo[n];

        return memo[n] = cost[n] + min(solve(cost, memo, n + 1), solve(cost, memo, n + 2));
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        // vector<int> memo(cost.size(), -1);
        // solve(cost, memo, 0);
        // return min(memo[0], memo[1]);

        // vector<int> dp(cost.size() + 2);

        // for (int i = cost.size() - 1; i >= 0; i--) {
        //     dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        // }

        // return min(dp[0], dp[1]);

        int next1 = 0;
        int next2 = 0;
        for (int i = cost.size() - 1; i >= 0; i--) {
            int curr = cost[i] + min(next1, next2);
            next2 = next1;
            next1 = curr;
        }

        return min(next1, next2);
    }
};

class Solution {
private:
    int dfs(int n, vector<int>& memo) {
        if (n <= 2) return n;

        if (memo[n] != -1) return memo[n];

        return memo[n] = dfs(n - 1, memo) + dfs(n - 2, memo);
    }

public:
    int climbStairs(int n) {
        // vector<int> memo(n + 1, -1);
        // return dfs(n, memo);
        // vector<int> dp(n + 1);
        // dp[0] = dp[1] = 1;

        // for (int i = 2; i <= n; i++) {
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // }

        // return dp[n];
        int prev2 = 1;
        int prev1 = 1;

        for (int i = 2; i <= n; i++) {
            int tmp = prev2 + prev1;
            prev2 = prev1;
            prev1 = tmp;
        }

        return prev1;
    }
};

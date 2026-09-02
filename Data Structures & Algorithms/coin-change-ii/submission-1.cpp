class Solution {
private:
    int solve(int amount, const vector<int>& coins, vector<vector<int>>& memo, int start) {
        if (amount == 0) return 1;
        if (start == coins.size()) return 0;
        if (memo[start][amount] != -1) return memo[start][amount];

        int take = 0;
        if (coins[start] <= amount) {
            take = solve(amount - coins[start], coins, memo, start);
        }
        int skip = solve(amount, coins, memo, start + 1);

        return memo[start][amount] = take + skip;
    }

public:
    int change(int amount, vector<int>& coins) {
        // vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        // return solve(amount, coins, memo, 0);

        // vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        // for (int i = 0; i < coins.size(); i++) {
        //     dp[i][0] = 1;
        // }

        // for (int i = coins.size() - 1; i >= 0; i--) {
        //     for (int j = 1; j <= amount; j++) {
        //         dp[i][j] = dp[i + 1][j];
        //         if (j >= coins[i]) {
        //             dp[i][j] += dp[i][j - coins[i]];
        //         }
        //     }
        // }

        // return dp[0][amount];

        vector<uint64_t> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = coins.size() - 1; i >= 0; i--) {
            for (int j = 1; j <= amount; j++) {
                if (j >= coins[i]) {
                    dp[j] += dp[j - coins[i]];
                }
            }
        }

        return dp[amount];
    }
};
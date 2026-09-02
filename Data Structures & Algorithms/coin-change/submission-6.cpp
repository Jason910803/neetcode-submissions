class Solution {
private:
    int solve(const vector<int>& coins, vector<int>& memo, int amount) {
        if (amount == 0) return 0;
        if (memo[amount] != -1) return memo[amount];

        int count = 1e9;
        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] <= amount) {
                count = min(solve(coins, memo, amount - coins[i]) + 1, count);
            }
        }

        return memo[amount] = count;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        // vector<int> memo(amount + 1, -1);
        // int ans = solve(coins, memo, amount);
        // return ans >= amount + 1 ? -1 : ans;

        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i < amount + 1; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        int ans = dp[amount];
        return ans == amount + 1 ? -1 : ans;
    }
};

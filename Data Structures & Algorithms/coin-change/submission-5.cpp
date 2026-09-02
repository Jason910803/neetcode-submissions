class Solution {
private:
    int solve(const vector<int>& coins, vector<int>& memo, int amount, int i) {
        if (i == amount) return 0;
        if (memo[i] != -1) return memo[i];

        int count = amount;
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= amount - i) {
                count = min(solve(coins, memo, amount, i + coins[j]), count);
            }
        }

        return memo[i] = 1 + count;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount, -1);
        int ans = solve(coins, memo, amount, 0);
        return ans >= amount + 1 ? -1 : ans;
    }
};

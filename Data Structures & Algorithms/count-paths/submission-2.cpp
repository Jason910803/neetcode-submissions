class Solution {
private:
    int solve(vector<vector<int>>& memo, int m, int n, int i, int j) {
        if (i == m - 1 || j == n - 1) return 1;

        if (memo[i][j] != -1) return memo[i][j];

        return memo[i][j] = solve(memo, m, n, i + 1, j) + solve(memo, m, n, i, j + 1);
    }

public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> memo(m, vector<int>(n, -1));

        // vector<vector<int>> dp(m, vector<int>(n, 1));
        vector<int> dp(n, 1);
        
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                dp[j] = dp[j] + dp[j + 1];
            }
        }

        return dp[0];
    }
};
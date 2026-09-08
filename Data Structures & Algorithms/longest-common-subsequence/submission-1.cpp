class Solution {
private:
    int solve(const string& text1, const string& text2, vector<vector<int>>& memo, int i, int j) {
        if (i >= text1.size() || j >= text2.size()) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        if (text1[i] == text2[j]) {
            memo[i][j] = 1 + solve(text1, text2, memo, i + 1, j + 1);
        } else {
            memo[i][j] = max(
                solve(text1, text2, memo, i + 1, j),
                solve(text1, text2, memo, i, j + 1)
            );
        }

        return memo[i][j];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), -1));
        // return solve(text1, text2, memo, 0, 0);

        int m = text1.size();
        int n = text2.size();
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        vector<int> dp(n + 1, 0);

        for (int i = m - 1; i >= 0; i--) {
            int diag = dp[n];
            for (int j = n - 1; j >= 0; j--) {
                int temp = dp[j];
                if (text1[i] == text2[j]) {
                    dp[j] = 1 + diag;
                } else {
                    dp[j] = max(dp[j], dp[j + 1]);
                }
                diag = temp;
            }
        }

        return dp[0];
    }
};
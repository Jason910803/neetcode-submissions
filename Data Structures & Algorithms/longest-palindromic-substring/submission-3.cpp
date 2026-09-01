class Solution {
private:
    int solve(const string& s, vector<vector<int>>& memo, int i, int j) {
        if (i >= j) return 1;

        if (memo[i][j] != -1) return memo[i][j];

        if (s[i] == s[j]) {
            return memo[i][j] = solve(s, memo, i + 1, j - 1);
        }

        return memo[i][j] = 0;
    }

public:
    string longestPalindrome(string s) {
        // manacher's algo is this problem
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));

        int len = 1;
        int start = 0;

        // for (int i = 0; i < n - 1; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (solve(s, memo, i, j) && (j - i + 1) > len) {
        //             len = j - i + 1;
        //             start = i;
        //         }
        //     }
        // }

        // return s.substr(start, len);
        // vector<vector<int>> dp(n, vector<int>(n, 1));

        // for (int i = n - 2; i >= 0; i--) {
        //     for (int j = n - 1; j > i; j--) {
        //         if (s[i] == s[j]) {
        //             dp[i][j] = dp[i + 1][j - 1];
        //             if (dp[i][j] && (j - i + 1) > len) {
        //                 len = j - i + 1;
        //                 start = i;
        //             }
        //         } else {
        //             dp[i][j] = 0;
        //         }
        //     }
        // }

        vector<int> dp(n, 1);

        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (s[i] == s[j]) {
                    dp[j] = dp[j - 1];
                    if (dp[j] && (j - i + 1) > len) {
                        len = j - i + 1;
                        start = i;
                    }
                } else {
                    dp[j] = 0;
                }
            }
        }

        return s.substr(start, len);
    }
};

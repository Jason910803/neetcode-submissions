class Solution {
private:
    int solve(const string& s, vector<int>& memo, int i) {
        if (i >= s.size()) return 1;        // success
        if (s[i] == '0') return 0;          // leading zero
        if (memo[i] != -1) return memo[i];

        int ways = solve(s, memo, i + 1);
        if (i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            ways += solve(s, memo, i + 2);
        }

        return memo[i] = ways;
    }

public:
    int numDecodings(string s) {
        // vector<int> memo(s.size(), -1);
        // return solve(s, memo, 0);

        // int n = s.size();
        // vector<int> dp(n + 1, 1);

        // for (int i = n - 1; i >= 0; i--) {
        //     if (s[i] == '0') {
        //         dp[i] = 0;
        //     } else {
        //         dp[i] = dp[i + 1];
        //         if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
        //             dp[i] += dp[i + 2];
        //         }
        //     }
        // }

        // return dp[0];

        int n = s.size();
        int next1 = 1;
        int next2 = 1;

        for (int i = n - 1; i >= 0; i--) {
            int curr = 0;
            if (s[i] != '0') {
                curr = next1;
                if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                    curr += next2;
                }
            }

            next2 = next1;
            next1 = curr;
        }

        return next1;
    }
};
class Solution {
private:
    int solve1(const string& s, vector<vector<int>>& memo, int i, int j) {
        if (i >= j) return 1;

        if (memo[i][j] != -1) return memo[i][j];

        if (s[i] == s[j]) {
            return memo[i][j] = solve1(s, memo, i + 1, j - 1);
        }

        return memo[i][j] = 0;
    }

    int solve2(const string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
 
public:
    int countSubstrings(string s) {
        int n = s.size();
        // vector<vector<int>> memo(n, vector<int>(n, -1));
        
        // int count = 0;
        // for (int i = 0; i < n; i++) {
        //     for (int j = i; j < n; j++) {
        //         if (solve1(s, memo, i, j)) {
        //             count++;
        //         }
        //     }
        // }

        // return count;

        // int count = 0;
        // vector<int> dp(n, 1);
        // for (int i = n - 1; i >= 0; i--) {
        //     for (int j = n - 1; j >= i; j--) {
        //         if (i == j) {
        //             count++;
        //         } else {
        //             if (s[i] == s[j]) {
        //                 dp[j] = dp[j - 1];
        //                 if (dp[j]) {
        //                     count++;
        //                 }
        //             } else {
        //                 dp[j] = 0;
        //             }
        //         }
        //     }
        // }

        // return count;

        int count = 0;
        for (int i = 0; i < n; i++) {
            count += solve2(s, i, i);
            count += solve2(s, i, i + 1);
        }

        return count;
    }
};

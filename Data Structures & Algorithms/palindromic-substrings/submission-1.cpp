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
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, memo, i, j)) {
                    count++;
                }
            }
        }

        return count;
    }
};

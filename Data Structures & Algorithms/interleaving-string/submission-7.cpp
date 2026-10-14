class Solution {
private:
    vector<vector<int>> memo;

    bool dfs(const string& s1, const string& s2, const string& s3, int i, int j) {
        if (i == s1.size() && j == s2.size()) {
            return true;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int k = i + j;
        bool res = false;

        if (i < s1.size() && s3[k] == s1[i]) {
            res = dfs(s1, s2, s3, i + 1, j);
        }

        if (!res && j < s2.size() && s3[k] == s2[j]) {
            res = dfs(s1, s2, s3, i, j + 1);
        }

        memo[i][j] = res;
        return res;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (m + n != s3.size()) {
            return false;
        }

        memo.assign(m + 1, vector<int>(n + 1, -1));
        return dfs(s1, s2, s3, 0, 0);
    }
};

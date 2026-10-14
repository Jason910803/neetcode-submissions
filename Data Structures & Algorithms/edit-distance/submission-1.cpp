class Solution {
private:
    vector<vector<int>> memo;

    int dfs(const string& word1, const string& word2, int i, int j) {
        if (i == 0) return j;
        if (j == 0) return i;
        if (memo[i][j] != -1) return memo[i][j];

        if (word1[i - 1] == word2[j - 1]) {
            memo[i][j] = dfs(word1, word2, i - 1, j - 1);
        } else {
            int insertOp = dfs(word1, word2, i, j - 1);
            int deleteOp = dfs(word1, word2, i - 1, j);
            int replaceOp = dfs(word1, word2, i - 1, j - 1);
            memo[i][j] = min({insertOp, deleteOp, replaceOp}) + 1;
        }

        return memo[i][j];
    }

public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        memo.assign(m + 1, vector<int>(n + 1, -1));
        
        return dfs(word1, word2, m, n);
    }
};

class Solution {
private:
    int solve(
        const string& s,
        const unordered_set<string>& wordSet,
        vector<int>& memo,
        int maxLen,
        int i
    ) {
        if (i >= s.size()) return 1;
        if (memo[i] != -1) return memo[i];

        for (int len = 1; len <= min(maxLen, (int)s.size() - i); len++) {
            string word = s.substr(i, len);
            if (wordSet.count(word) && solve(s, wordSet, memo, maxLen, i + len)) {
                return memo[i] = 1;
            }
        }

        return memo[i] = 0;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        int maxLen = 0;

        for (const string& word : wordDict) {
            maxLen = max(maxLen, (int)word.size());
        }

        return solve(s, wordSet, memo, maxLen, 0) == 1;
    }
};
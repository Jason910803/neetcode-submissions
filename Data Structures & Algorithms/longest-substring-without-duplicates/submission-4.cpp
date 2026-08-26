class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        unordered_set<char> charSet;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            while (charSet.count(s[right])) {
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[right]);
            result = max(result, right - left + 1);
        }

        return result;
    }
};

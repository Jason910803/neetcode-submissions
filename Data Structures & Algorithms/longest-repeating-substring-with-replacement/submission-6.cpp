class Solution {
public:
    int characterReplacement(string s, int k) {
        return sol2(s, k);
    }

    int sol2(string& s, int& k) {
        vector<int> count(26);
        int result = 0;
        int left = 0;
        int maxCount = 0;

        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);

            if (right - left + 1 - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }

    int sol1(string& s, int& k) {
        vector<int> charCount(26);
        int result = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            charCount[s[right] - 'A']++;
            int maxLen = *max_element(charCount.begin(), charCount.end());

            while (right - left + 1 - maxLen > k) {
                charCount[s[left] - 'A']--;
                left++;
                maxLen = *max_element(charCount.begin(), charCount.end());
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};

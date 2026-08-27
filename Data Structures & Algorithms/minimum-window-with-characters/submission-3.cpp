class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) {
            return "";
        }

        vector<int> t_count(128);
        int required = 0;
        for (char c : t) {
            if (t_count[c] == 0) {
                required++;
            }
            t_count[c]++;
        }

        int min_len = INT_MAX;
        int start = -1;
        int left = 0;
        int current = 0;
        vector<int> s_count(128);

        for (int right = 0; right < s.size(); right++) {
            s_count[s[right]]++;
            if (t_count[s[right]] > 0 && s_count[s[right]] == t_count[s[right]]) {
                current++;
            }

            while (current == required) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    start = left;
                }

                // shrink the left pointer
                s_count[s[left]]--;
                if (t_count[s[left]] > 0 && s_count[s[left]] < t_count[s[left]]) {
                    current--;
                }
                left++;
            }
        }

        return start == -1 ? "" : s.substr(start, min_len);
    }
};

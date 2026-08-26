class Solution {
   public:
    bool isAnagram(string s, string t) {
        // if (s.size() != t.size()) return false;

        // vector<int> count(26, 0);
        // for (int i = 0; i < s.size(); i++) {
        //     count[s[i] - 'a']++;
        //     count[t[i] - 'a']--;
        // }

        // for (int c : count) {
        //     if (c != 0) return false;
        // }

        // return true;

        return another(s, t);
    }

    bool another(const string& s, const string& t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> count;
        for (int i = 0; i < s.size(); i++) {
            count[s[i]]++;
            count[t[i]]--;
        }

        for (const auto& [key, value] : count) {
            if (value != 0) return false;
        }

        return true;
    }
};

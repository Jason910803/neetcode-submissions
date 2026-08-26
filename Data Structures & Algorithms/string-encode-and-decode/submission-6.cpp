class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded;
        for (const string& str : strs) {
            int len = str.size();
            encoded += to_string(len) + '#' + str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }

            // string s_len = s.substr(i, j - i);
            // int len = stoi(s_len);
            int len = stoi(s.substr(i, j - i));
            result.push_back(s.substr(j + 1, len));

            i = j + len + 1; 
        }

        return result;
    }
};

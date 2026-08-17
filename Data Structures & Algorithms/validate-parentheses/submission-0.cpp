class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        map<char, int> mp = {
            {'(', 1},
            {')', 2},
            {'{', 3},
            {'}', 4},
            {'[', 5},
            {']', 6}
        };

        for (int i = 0; i < s.size(); i++) {
            int idx = mp[s[i]];
            if (idx % 2 == 0) {
                if (st.empty())
                    return false;
                else if (mp[st.top()] != idx - 1)
                    return false;
                else
                    st.pop();
            } else {
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};

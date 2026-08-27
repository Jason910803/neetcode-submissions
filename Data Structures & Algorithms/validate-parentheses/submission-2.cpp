class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // push the corresponding close bracket if c is open bracket
            if (c == '(') {
                st.push(')');
            } else if (c == '[') {
                st.push(']');
            } else if (c == '{') {
                st.push('}');
            } else {
                // c is close bracket
                if (!st.empty()) {
                    if (st.top() != c) {
                        return false;
                    }

                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

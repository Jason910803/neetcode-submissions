class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& s : tokens) {
            if (s.size() > 1 || isdigit(s[0])) {
                st.push(stoi(s));
            } else {
                int second = st.top(); st.pop();
                int first = st.top(); st.pop();
                int result;

                switch (s[0]) {
                    case '+':
                        result = first + second;
                        st.push(result);
                        break;
                    
                    case '-':
                        result = first - second;
                        st.push(result);
                        break;
                    
                    case '*':
                        result = first * second;
                        st.push(result);
                        break;
                    
                    case '/':
                        result = first / second;
                        st.push(result);
                        break;
                }
            }
        }

        return st.top();
    }
};

class MinStack {
private:
    stack<int> main_st;
    stack<int> min_st;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        main_st.push(val);
        if (min_st.empty() || val <= min_st.top()) {
            min_st.push(val);
        }
    }
    
    void pop() {
        if (main_st.top() == min_st.top()) {
            min_st.pop();
        }
        main_st.pop();
    }
    
    int top() {
        return main_st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

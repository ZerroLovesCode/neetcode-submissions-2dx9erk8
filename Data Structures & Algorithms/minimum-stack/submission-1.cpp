class MinStack {
public:
    std::stack<int> st, mini;
    MinStack() {
        
    }
    
    void push(int val) {
        cout << "HERE";
        st.push(val);
        if(!mini.empty()){
            mini.push(min(mini.top(), val));
        }
        else{
            mini.push(val);
        }
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
        }
        if(!mini.empty()){
            mini.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini.top();
    }
};

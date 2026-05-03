class Solution {
public:
    int eval(int t1, int t2, string op){
        if(op == "+") return t1 + t2;
        if(op == "-") return t1 - t2;
        if(op == "*") return t1 * t2;
        if(op == "/") return t1 / t2;

        return 0;
    }
    pair<int, int> getOps(stack<int> &st){
        int t2 = st.top();
        st.pop();
        int t1 = st.top();
        st.pop();
        return {t1, t2};
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        pair<int ,int> p;
        for(const string &x: tokens){
            if(x == "+"){
                p = getOps(st);
                st.push(eval(p.first, p.second, "+"));
            }
            else if(x == "-"){
                p = getOps(st);
                st.push(eval(p.first, p.second, "-"));
            }
            else if(x == "*"){
                p = getOps(st);
                st.push(eval(p.first, p.second, "*"));
            }
            else if(x == "/"){
                p = getOps(st);
                st.push(eval(p.first, p.second, "/"));
            }
            else{
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};

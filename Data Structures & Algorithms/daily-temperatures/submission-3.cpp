class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && temperatures[stk.top()] <= temperatures[i]){
                stk.pop();
            }
            if(!stk.empty()){
                ans[i] = stk.top() - i;
            }
            stk.push(i);
        }
        return ans;
    }
};

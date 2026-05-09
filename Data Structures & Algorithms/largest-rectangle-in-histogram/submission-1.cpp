class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n, n);
        vector<int> pse(n, -1);

        stack<int> nseSt;
        stack<int> pseSt;
        nseSt.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!nseSt.empty() && heights[nseSt.top()] >= heights[i]){
                nseSt.pop();
            }
            if(!nseSt.empty()){
                nse[i] = nseSt.top();
            }
            nseSt.push(i);
        }

        pseSt.push(0);
        for(int i=1;i<n;i++){
            while(!pseSt.empty() && heights[i] <= heights[pseSt.top()]){
                pseSt.pop();
            }
            if(!pseSt.empty()){
                pse[i] = pseSt.top();
            }
            pseSt.push(i);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            // cout << nse[i] << " " << pse[i]<<"\n";
            ans = max(ans, heights[i] * (nse[i] - pse[i] - 1));
        }
        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> mx_r(n, 0), mx_l(n, 0);
        for(int i=1;i<n;i++){
            mx_l[i] = max(mx_l[i-1], height[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            mx_r[i] = max(mx_r[i+1], height[i+1]);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            int x = min(mx_l[i], mx_r[i]);
            int vol = (x > height[i])?x-height[i]:0;
            ans += vol;  
        }
        return ans;
    }
};

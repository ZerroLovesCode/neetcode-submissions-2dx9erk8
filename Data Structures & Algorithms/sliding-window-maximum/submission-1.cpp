class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1, 0);
        deque<int> dq;
        int r = 0, l = 0;
        while(r < n){
            while(!dq.empty() && nums[r] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(r);
            if(l>dq.front()){
                dq.pop_front();
            }
            if(r+1 >= k){
                ans[l] = nums[dq.front()];
                l++;
            }
            r++;
        }
        return ans;
    }
};

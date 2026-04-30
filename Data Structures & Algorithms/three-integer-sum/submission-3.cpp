class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            int x = nums[i];
            if(i>0 && nums[i-1] == nums[i]){
                continue;
            }
            int target = -x;
            // find all pairs y, z st y + z = target;
            int l = i+1, r = n-1;
            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum == target){
                    ans.push_back({x, nums[l], nums[r]});
                    while(nums[l] == nums[l+1]){
                        l++;
                    }
                    while(nums[r] == nums[r-1]){
                        r--;
                    }
                  
                    l++;
                }
                if(sum < target){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return ans;
    }
};

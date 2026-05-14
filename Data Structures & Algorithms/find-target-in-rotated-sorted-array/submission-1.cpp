class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l <= r){
            int m = (l+r)/2;
            if(nums[m] == target){
                return m;
            }

            if(nums[l] <= nums[m]){
                //sorted portion is the left half
                if(nums[l] <= target && nums[m] >= target){
                    r = m-1;
                }
                else{
                    l = m+1;
                }
            }
            else{
                // sorted portion is the right half
                if(nums[r] >= target && nums[m] <= target){
                    l = m+1;
                }
                else{
                    r = m-1;
                }
            }
        }
        return -1;
    }
};

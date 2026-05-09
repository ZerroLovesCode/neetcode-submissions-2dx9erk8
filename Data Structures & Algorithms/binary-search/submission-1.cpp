class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<=r){
            int m = r - (r-l)/2;
            if(nums[m] == target){
                return m;
            }
            if(target > nums[m]){
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        return -1;
    }
};

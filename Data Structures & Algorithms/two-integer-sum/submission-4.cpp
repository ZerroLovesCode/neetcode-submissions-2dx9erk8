class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, bool> present;
        map<int, int> m;

        int n = nums.size();
        for(int i=0;i<n;i++){
            if(present[target - nums[i]]){
                return {m[target - nums[i]], i};
            }
            present[nums[i]] = true;
            m[nums[i]] = i;
        }
    }
};

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, bool> m;
        for(const auto &x: nums){
            if(m[x]){
                return true;
            }
            m[x] = true;
        }
        return false;
    }
};
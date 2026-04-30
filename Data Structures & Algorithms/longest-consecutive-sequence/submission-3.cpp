class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for(int x: s){
            if(s.find(x-1) != s.end()){
                continue;
            }
            int temp = 1;
            int next = x+1;
            while(s.find(next) != s.end()){
                temp++;
                next++;
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};

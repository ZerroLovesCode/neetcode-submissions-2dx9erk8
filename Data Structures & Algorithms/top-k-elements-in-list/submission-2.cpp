class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> freq(n+1);
        map<int, int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(const auto &x: m){
            freq[x.second].push_back(x.first);
        }
        vector<int> ans;
        int count = 0;
        for(int i=n;i>=0;i--){
            if(freq[i].size() != 0){
                for(const auto &x: freq[i]){
                    ans.push_back(x);
                    count++;
                }
            }
            if(count == k){
                break;
            }
        }
        return ans;
    }
};

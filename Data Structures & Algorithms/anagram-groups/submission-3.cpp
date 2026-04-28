class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> m;

        for(const string &x: strs){
            vector<int> v(26, 0);
            for(int i=0;i<x.length();i++){
                v[x[i] - 'a']++;
            }
            m[v].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto &x: m){
            ans.push_back(x.second);
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int l = 0, res = 0;
        for(int r = 0; r < s.length(); r++){
            if(m.find(s[r]) != m.end()){
                l = max(l, m[s[r]] + 1);
            }
            res = max(res, r - l +1);
            m[s[r]] = r;
        }
        // int n = s.length() - 1;
        // res = max(res, n - l);
        return res;
    }
};

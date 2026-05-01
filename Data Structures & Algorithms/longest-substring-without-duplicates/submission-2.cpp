class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int l = 0, r = 0;
        int n = s.length();
        map<char, int> f;
        while(r < n){
            f[s[r]]++;
            while(f[s[r]] > 1){
                f[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};

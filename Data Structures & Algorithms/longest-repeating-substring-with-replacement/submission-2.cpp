class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;

        int mf = 0;
        int l=0, r=0, ans = 1;
        while(r < s.length()){
            m[s[r]]++;
            mf = max(mf, m[s[r]]);
            while((r-l+1) - mf > k){
                m[s[l]]--;
                l++;
            }
            ans = max(ans, (r-l+1));
            r++;
        }
        return ans;
    }
};

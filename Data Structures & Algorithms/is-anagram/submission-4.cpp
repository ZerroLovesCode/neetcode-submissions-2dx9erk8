class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        vector<int> m(26, 0);
        int n = s.length();
        for(int i=0;i<n;i++){
            m[s[i] - 'a']++;
            m[t[i] - 'a']--;
        }
        for(int i=0;i<26;i++){
            if(m[i] != 0){
                return false;
            }
        }
        return true;
    }
};

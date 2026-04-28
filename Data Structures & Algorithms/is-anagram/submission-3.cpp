class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        int n = s.length();
        map<char, int> m1, m2;
        for(int i=0;i<n;i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }
        for(int i=0;i<n;i++){
            if(m1[s[i]] != m2[s[i]]){
                return false;
            }
        }
        return true;
    }
};

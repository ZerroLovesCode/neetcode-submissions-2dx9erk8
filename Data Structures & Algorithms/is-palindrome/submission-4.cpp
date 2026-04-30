class Solution {
public:
    bool isPalindrome(string s) {
        string ns = "";
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i])){
                ns += tolower(s[i]);
            }
        }
        int l=0, r = ns.size()-1;
        while(l < r){
            if(ns[l] != ns[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};

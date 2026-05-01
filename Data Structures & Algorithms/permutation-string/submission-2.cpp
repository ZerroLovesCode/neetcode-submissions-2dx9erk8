class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }
        vector<int> v2(26, 0);
        vector<int> v1(26, 0);
        for(const char &x: s1){
            v1[x - 'a']++;
        }
        // for(auto &x: v2){
        //     cout << x <<" ";
        // }
        // cout << "\n";
        int l = 0;
        for(int r=0;r<s2.length();r++){
            v2[s2[r] - 'a']++;
            // for(auto &x: v2){
            //     cout << x << " ";
            // }
            // cout << '\n';
            if((r - l + 1) > s1.size()){
                v2[s2[l] - 'a']--;
                l++;
            }
            if(v1 == v2){
                return true;
            }
        }
        return false;
    }

};

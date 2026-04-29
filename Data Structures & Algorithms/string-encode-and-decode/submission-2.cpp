class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(int i=0;i<strs.size();i++){
            int l = strs[i].length();
            s += to_string(l) + "|" + strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> ans;
        while(i<s.length()){
            string len = "";
            int l = 0;
            while(s[i] != '|'){
                len += s[i];
                i++;
            }
            i++;
            l = stoi(len);
            ans.push_back(s.substr(i, l));
            i += l;
        }
        return ans;
    }
};

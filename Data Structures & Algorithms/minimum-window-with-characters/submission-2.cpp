class Solution {
public:
    void print(map<char, int>m){
        for(auto x: m){
            cout << x.first <<" "<<x.second<<"\n";
        }
        cout << "\n-------\n";
    }
    bool contains(map<char, int> &ms, map<char, int> &mt){
        for(const auto &x: mt){
            if(ms[x.first] < mt[x.first]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(t.length() > s.length()){
            return "";
        }
        map<char, int> ms, mt;
        for(const auto &x: t){
            mt[x]++;
        }
        //print(mt);
        int l=0, r=0;
        string ans = "";
        bool flag = false;
        while(r<s.length()){
            ms[s[r]]++;
            // print(ms);
            while(contains(ms, mt)){
                string temp = s.substr(l, (r-l+1));
                if(!flag){
                    ans = temp;
                }
                else{
                    ans = temp.length()<ans.length()? temp:ans;
                }
                flag = true;
                ms[s[l]]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};

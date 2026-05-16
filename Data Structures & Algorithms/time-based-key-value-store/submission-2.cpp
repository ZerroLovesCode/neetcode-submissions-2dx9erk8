class TimeMap {
public:
    map<string, vector<pair<string, int>>> tm;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        tm[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(tm.find(key) == tm.end()) return "";
        if(tm[key][0].second > timestamp) return "";
        int l = 0, r = tm[key].size()-1;
        while(l <= r){
            int m = (l+r)/2;
            int ts = tm[key][m].second;
            if(ts == timestamp){
                return tm[key][m].first;
            }
            if(ts > timestamp){
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        return tm[key][r].first;
    }
};

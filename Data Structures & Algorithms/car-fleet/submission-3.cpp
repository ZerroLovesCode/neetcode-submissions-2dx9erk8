class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        int n  = position.size();
        for(int i=0;i<n;i++){
            v.push_back({position[i], speed[i]});
        }
        sort(v.rbegin(), v.rend());
        stack<double> st;
        for(int i=0;i<n;i++){
            double time = (double)(target - v[i].first)/v[i].second;
            // cout << time << "\n";
            if(st.empty()){
                st.push(time);
            }
            else{
                if(st.top() < time){
                    st.push(time);
                }
            }
        }
        return st.size();
    }
};

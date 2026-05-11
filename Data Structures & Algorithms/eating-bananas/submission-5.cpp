class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int m = *max_element(piles.begin(), piles.end());
        // k lies between 1 and m
        int l = 1, r = m;
        int ans = r;
        while(l <= r){
            int m = r - (r-l)/2;
            int hours = 0;
            for(int i=0;i<n;i++){
                hours += ceil((double)(piles[i])/m);
            }
            if(hours > h){
                l = m+1;
            }
            else{
                ans = m;
                r = m-1;
            }
        }
        // cout << l<< " " << ans << " " << r;
        return ans;
    }
};

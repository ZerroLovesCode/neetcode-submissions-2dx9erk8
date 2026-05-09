class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        // find the row where the target might lie  => r[0] < t < r[-1]
        int l = 0, r = rows - 1;
        int targetRow;
        while(l <= r){
            int m = (l+r)/2;
            if(matrix[m][0] == target || matrix[m][cols-1] == target){
                return true;
            }
            if(matrix[m][0] < target && matrix[m][cols-1] > target){
                // found the row where the answer might lie.
                targetRow = m;
                break;
            }
            if(matrix[m][0] < target){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        l = 0, r = cols-1;
        while(l <= r){
            int m = (l+r)/2;
            int val = matrix[targetRow][m];
            if(val == target){
                return true;
            }
            if(val > target){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return false;
    }
};

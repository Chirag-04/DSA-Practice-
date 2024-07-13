class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n =  mat.size();
        int m = mat[0].size();
        int lo=0  , hi = n-1;
        int mid = -1;
        while(lo <=hi){
            mid =  (lo+hi)/2;
            if(target >= mat[mid][0] and target <= mat[mid][m-1]) break;
            else if(target < mat[mid][0]){
                hi = mid-1;
            }
            else if(target > mat[mid][m-1]){
                lo = mid+1;
            }
        }

        // cout<<mid<<endl;
        int l = 0 , h = m-1;
        while(l <=h ){
            int m =  (l+h)/2;
            // cout<<mat[mid][m]<<endl;
            if(mat[mid][m] == target) return true;
            else if(target > mat[mid][m]) l = m+1;
            else h = m-1;
        }
        return false;
    }
};
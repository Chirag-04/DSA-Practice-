class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int n = mat.size() ;
        int m = mat[0].size();
        vector<int>row(n , INT_MAX);
        vector<int>col(m , INT_MIN);
        //
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                // ith row jth col 
                row[i] = min(row[i] , mat[i][j]);
                col[j] = max(col[j] , mat[i][j]);
            }
        }
        int ct = 0;
        vector<int>ans;
        for(int i=0;  i<n ; i++){
            for(int j=0  ; j<m ; j++){
                if(row[i] == col[j]){
                    ans.push_back(row[i]);
                }
            }
        }
        return ans ;
    }
};
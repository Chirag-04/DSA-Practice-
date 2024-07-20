class Solution {
public:
   using ll = long long;
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> ans(n , vector<int>(m , 0));
        for(int i=0 ; i<n ; i++){
            ans[i][0] = rowSum[i];
        }


        for(int j= 0 ;  j<m-1  ;j++){
            ll given = 0;
            ll req = colSum[j];
            for(int i= 0 ;i<n ; i++) given+=ans[i][j];
            for(int i=0 ; i<n ; i++){
               ll diff = given - req;
               ll mini = min(diff  , (ll)ans[i][j]);
               ans[i][j]-=mini;
               ans[i][j+1]+=mini;
               given-=mini;  
            }
        }

        return ans;
    }
};
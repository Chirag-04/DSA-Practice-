class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0; i <n ; i++){
            for(int j=0 ; j<m ;j++){
                int left = 0 , up = 0  , diag = 0;
               if(j>=1) left = grid[i][j-1];
                if(i>=1)up =  grid[i-1][j];
                if(i>=1 and j>=1) diag =  grid[i-1][j-1];
                grid[i][j]= grid[i][j] + left + up - diag;
            }
        }
        // ans 
        
        int ans  = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] <=k) ans++;
            }
        }
        return ans ;
    }
};
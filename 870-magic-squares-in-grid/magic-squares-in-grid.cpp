class Solution {
public:
    // let write brute force first 
    void check(int r  , int c , vector<vector<int>>& grid  , int&ans){
        int total_sum = 0 ;
        set<int>s;
        for(int i=0 ; i<3 ; i++){
            for(int j=0 ; j<3  ; j++){
                total_sum+=grid[i+r][j+c];
                if(grid[i+r][j+c] >0 and grid[i+r][j+c]<=9) s.insert(grid[i+r][j+c] );
            }
        }
        // total sum 
        if(s.size()!=9) return ;

        // cheekc 
        for(int i=0 ; i<3 ; i++){
            int rsum = 0 ;
            for(int j=0 ; j<3  ; j++){
                rsum+=grid[i+r][j+c];
            }
            if(3*rsum != total_sum) return ;
        }

        // check column
         for(int i=0 ; i<3 ; i++){
            int csum = 0 ;
            for(int j=0 ; j<3  ; j++){
                csum+=grid[r+j][c+i];
            }
            if(3*csum != total_sum) return ;
        }

        // check diagrnoles 
        if(grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2] != (total_sum)/3) return ;
        if(grid[r+2][c] + grid[r+1][c+1] + grid[r][c+2] != (total_sum)/3) return ;

        ans++;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      int ans =  0;
      for(int i=0; i<n-2 ; i++){
        for(int j=0 ; j<m-2 ; j++){
                check(i , j , grid , ans);
        }
      }
      return ans ;
    }
};
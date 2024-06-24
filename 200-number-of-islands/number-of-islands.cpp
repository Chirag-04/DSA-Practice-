class Solution {
public:
    //1 represent the land cell 
    //0 represent the water cell
    int delr[4] = {-1 , 0 , 1 , 0};
    int delc[4] = {0 , 1 , 0 , -1};
    int n , m;
    void dfs(int r  , int c , vector<vector<char>>& grid  ,
    vector<vector<int>>&vis){
        vis[r][c] = 1;
        for(int i=0 ; i<4 ; i++){
            int nr =  r + delr[i];
            int nc =  c + delc[i];
   if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc]=='1' and 
   !vis[nr][nc]){

    dfs(nr , nc , grid , vis);
   }         
        }
    }
    int numIslands(vector<vector<char>>& grid) {
       n = grid.size();
       m = grid[0].size();
       int ans  = 0;
       vector<vector<int>>vis(n , vector<int>(m ,0));
       // grid -> adjacency list 
       for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            // if it is 1 
            // go and cover the entire island
            if(grid[i][j] =='1' and vis[i][j] == 0){
                ans++;
                dfs(i , j , grid , vis);
            }
        }
       } 
       return ans ;
    }
};
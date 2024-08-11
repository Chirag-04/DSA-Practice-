class Solution {
public:
    int n , m;
    int delr[4] = {-1 , 0 , 1 , 0};
    int delc[4] = {0 , 1  ,0 , -1};
    void dfs(int r , int c , vector<vector<int>>& grid ,
    vector<vector<int>>&vis ){
        vis[r][c]= 1;
        for(int i=0 ; i<4 ; i++){
            int nr  =  r + delr[i];
            int nc = c + delc[i];
            if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc]
             and grid[nr][nc]==1){
                dfs(nr , nc  , grid , vis);
             }
        }
    }
    int count_island(vector<vector<int>>& grid){
        vector<vector<int>>vis(n , vector<int>(m, 0));
        int island = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(!vis[i][j] and grid[i][j]==1){
                    dfs(i , j , grid , vis);
                    island++;
                }
            }
        }
        return island;
    }
    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int  ct = count_island(grid);
        if(ct > 1) return 0;
        if(ct == 0) return 0;
        for(int i= 0 ; i<n ; i++){
            for(int j= 0 ; j<m ; j++){
                if(grid[i][j] == 1){
                    grid[i][j]= 0;
                    if(count_island(grid) !=1 ) return 1;
                    grid[i][j]= 1;

                }
            }
        }
        return 2;
    }
};
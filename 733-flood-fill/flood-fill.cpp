class Solution {
public:
    int delr[4] = {-1 , 0, 1 , 0};
    int delc[4] = {0 , 1  , 0 , -1};
    int n  , m;
    
    void dfs(int r , int c , int color , vector<vector<int>>& image , vector<vector<int>>&vis){
        vis[r][c] =  1;
        for(int i=0 ; i<4 ; i++){
            int nr =  r + delr[i];
            int nc =  c + delc[i];
        if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc] and image[nr][nc]== color ){
            dfs(nr , nc  , color , image , vis);
        }    
        }   
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         n = image.size();
         m =  image[0].size();
         vector<vector<int>>vis(n , vector<int>(m , 0));
         dfs(sr , sc , image[sr][sc] , image ,vis);

         for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(vis[i][j] == 1){
                    image[i][j] =  color;
                }
            }
         }
         //
        //  for(int i=0 ; i<n ; i++){
        //     for(int j=0 ; j<m ; j++){
        //         cout<<image[i][j]<<" ";
        //     }
        //     cout<<endl;
        //  }

        return image ;
    }
};
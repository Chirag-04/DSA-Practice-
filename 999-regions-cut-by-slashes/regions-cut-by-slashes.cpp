class Solution {
public:
    int delr[4] = {-1 , 0 , 1 ,0};
    int delc[4] = {0 , 1 , 0 , -1};
    void dfs(int r , int c , vector<vector<int>>&vis  , vector<vector<int>>&arr , int m){
        vis[r][c] = 1;
        for(int i=0 ; i<4 ; i++){
            int nr =  r + delr[i];
            int nc =  c + delc[i];
            if(nr>=0 and nr<m and nc>=0 and nc<m and arr[nr][nc] ==0 and
            !vis[nr][nc]){
                dfs(nr  , nc , vis , arr , m);
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>>arr(3*n , vector<int>(3*n , 0)); 
        for(int i= 0 ;i<n  ; i++){
            int j =0 ;
            while( j < grid[i].size()){
                // cout<<i<<" "<<j<<" "<<grid[i][j]<<""endl;
                if(grid[i][j] =='/'){
                    int r =  3*i , c = 3*j;
                    arr[r][c+2] = 1;
                    arr[r+2][c] = 1;
                    arr[r+1][c+1] = 1;
                    j++;
                }else if(grid[i][j] == '\\'){
                    cout<<"this"<<i<<" "<<j<<endl;
                    int r =  3*i , c = 3*j;
                    arr[r][c]= 1;
                    arr[r+1][c+1] = 1;
                    arr[r+2][c+2] = 1;
                    j++;
                }else j++;
            }
        }
        for(int i=0 ; i<arr.size() ; i++){
            for(int j=0 ; j<arr.size(); j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        // we have arr and we have to find totoal island 
        int m = arr.size();
        vector<vector<int>>vis(m , vector<int>(m , 0));
        int ans = 0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<m ; j++){
                if(!vis[i][j] and arr[i][j]==0){
                    dfs(i , j , vis  , arr , m);
                    ans++;
                }
            }
        }
        return ans;
    }
};
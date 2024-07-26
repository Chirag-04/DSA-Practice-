class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
         vector<vector<int>>dis(n , vector<int>(n ,INT_MAX));
        
        for(int i=0  ;i<n ; i++) dis[i][i] = 0; // imp
        for(int i= 0 ;i<edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            dis[u][v] = wt;
            dis[v][u] = wt;
        }
        
        for(int via =0 ;via<n ;via++){
            for(int i=0 ; i<n ; i++){
                for(int j= 0 ;j<n;j++){
                     if(dis[i][via] !=INT_MAX and 
                     dis[via][j]!=INT_MAX){
                    dis[i][j] = min(dis[i][j] , 
                    dis[i][via] + dis[via][j]);                        
                     }

                }
            }
        }
        
        //
        int ans  = n+1;
        int res=-1;
        for(int i=0 ; i< n ;i++){
             int count = 0 ;
            for(int j= 0 ; j<n ; j++){
                if(dis[i][j]!=INT_MAX and dis[i][j]<=distanceThreshold) count++;
            }
            if(count <= ans){
                ans = count ;
                res = i;
            }
        }
         return res;
    }
};
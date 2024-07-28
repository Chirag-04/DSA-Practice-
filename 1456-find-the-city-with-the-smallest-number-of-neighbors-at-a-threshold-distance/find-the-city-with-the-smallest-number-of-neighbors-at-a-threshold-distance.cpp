class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        // we can use floydd warshall algo
        // as we can traverse from a->b or a->k->b
        vector<vector<int>>store(n , vector<int>(n ,INT_MAX));
        for(auto it: edges){
            int a = it[0];
            int b = it[1];
            int wt =  it[2];
            store[a][b] =  wt;
            store[b][a] =  wt;
        }
        for(int i=0; i<n ;i++) store[i][i]= 0;
        //
        for(int via= 0 ;via<n ;via++){
            for(int i=0; i <n ; i++){
                for(int j=0; j<n ; j++){
                    if(i == j) continue;
                  if(store[i][via]!=INT_MAX and store[via][j]!=INT_MAX  )  
                  store[i][j] = min(store[i][j] , store[i][via]+store[via][j]);
                }
            }
        }
        //
        int mini =  INT_MAX;
        int index =  -1;
        for(int i=0; i <n ; i++){
            int count = 0 ;
            for(int j=0 ; j<n ; j++){
                if(store[i][j]!=INT_MAX and store[i][j] <= threshold){
                    count++;
                }
            }

            if(count  <=  mini){
                mini = count ;
                index = i;
            }
        }
        return index;
    }
};
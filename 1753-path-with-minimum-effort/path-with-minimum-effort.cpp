class Solution {
public:
    using PPI = pair< int , pair<int ,int>>;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        queue<PPI>pq;
        pq.push({0  , {0 , 0}});
        int delr[4] = {-1 , 0 , 1 , 0};
        int delc[4] = {0  , 1  , 0 , -1};
        vector<vector<int>>path(n , vector<int>(m , 1e9));
        path[0][0] = 0 ;
        while(!pq.empty()){
            int dis = pq.front().first;
            int r = pq.front().second.first;
            int c=  pq.front().second.second;
            pq.pop();
       for(int i=0 ; i<4 ; i++){
        int nr  =  r + delr[i];
        int nc =  c+ delc[i];
        if(nr>=0 and nr<n and nc>=0 and nc<m){
            // we want max diff
            int newEffort =  max(dis , abs(heights[nr][nc] - heights[r][c]) );
            if(newEffort < path[nr][nc]){
                path[nr][nc] =  newEffort;
            pq.push({ newEffort  ,{nr , nc}});
            }
        }
       }     
        }

        return path[n-1][m-1];
    }
};
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
         vector<int>inDegree(n , 0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            //  it[0] => it[1]
            inDegree[it[1]]++;
        }

        int ans = -1;
        int count =0 ;
        for(int i=0; i < n ; i++){
            if(inDegree[i] == 0){
                ans = i;
                 count++;
            }
            if(count >1) return -1;
        }
       
       return ans;
    }
};
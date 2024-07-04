class Solution {
public:
    // good question for practising traversal on array concept
    void dfs(int index , vector<vector<int>>& stones,  vector<int>&vis){
        vis[index] = 1 ;
        for(int j= 0 ;j<stones.size() ; j++){
            if(!vis[j]){
                if(stones[index][0] == stones[j][0] or stones[index][1] == stones[j][1]){
                    dfs(j , stones , vis);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int>vis(n);
        int groups = 0 ;
        for(int i= 0 ; i<n ; i++){
            if(!vis[i]){
                groups++;
                dfs(i , stones , vis);
            }
        }
        return n-groups;
        
    }
};
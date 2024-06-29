class Solution {
public:
    void dfs(int start  , vector<int>&vis , vector<int>&temp , vector<int>adj[]){
        vis[start] = 1;
        for(auto it : adj[start]){
            if(!vis[it]){
                temp.push_back(it);
                dfs(it , vis , temp  ,adj);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<vector<int>>ans;
        for(auto it : edges){
            int a =  it[0];
            int b = it[1];
            // a->b
            adj[b].push_back(a);
        }
        // i have to rull a loop on component
        for(int i=0 ; i<n ; i++){
            vector<int>temp;
            vector<int>vis(n);
            dfs(i , vis , temp  , adj);
            sort(temp.begin() , temp.end());
            ans.push_back(temp);
        }

        return ans ;
    }
};
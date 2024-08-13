class Solution {
public:
    unordered_set<int>s;
    void dfs(int start , vector<int>adj[] , vector<int>&vis , int&ans){
        vis[start] = 1;
        ans++;
        for(auto it : adj[start]){
            if(!vis[it] and !s.contains(it)){
                dfs(it , adj , vis , ans);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int>adj[n];
        for(auto it : edges){
            int a =  it[0];
            int b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        // created the graph 
        for(auto it :restricted ){
            s.insert(it);
        }
        vector<int>vis(n , 0);
        // created 
        int ans  = 0;
        dfs(0 , adj , vis  , ans);
        return ans ;
    }
};
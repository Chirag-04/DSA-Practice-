class Solution {
public:
    void dfs(int start , vector<int>&vis ,vector<int>adj[]
     , int&v , int&e){
        // new vertex
        v+=1;
        vis[start] = 1;
        for(auto it : adj[start]){
            //  it will run for each child of a node 
            e+=1;
            if(!vis[it]){
                dfs(it , vis , adj , v , e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto it : edges){
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        // 
        int ans = 0 ;
        vector<int>vis(n , 0);
        for(int i=0 ; i<n ; i++){

            if(!vis[i]){
                // set<int>s;
                int v =0;
                int e = 0;
                dfs(i , vis ,adj , v , e);
                cout<<i<<" "<<v<< " "<<e<<endl;
                if(e == (v*(v-1))) ans++;
            }
        }
        // cout<<ans<<endl;
        return ans;
    }
};
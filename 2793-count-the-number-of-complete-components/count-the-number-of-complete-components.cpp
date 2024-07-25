class Solution {
public:
    void dfs(int start , vector<int>&vis , set<int>&s ,vector<int>adj[]){
        s.insert(start);
        vis[start] = 1;
        for(auto it : adj[start]){
            if(!vis[it]){
                dfs(it , vis , s , adj);
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
                set<int>s;
                dfs(i , vis ,s , adj);
                int v = s.size();
                cout<<"v"<<v<<endl;
                int e = 0;
                for(auto it: s){
                    e+=adj[it].size();
                }
                cout<<"e"<<e<<endl;
                if(e == (v*(v-1))) ans++;
            }
        }
        // cout<<ans<<endl;
        return ans;
    }
};
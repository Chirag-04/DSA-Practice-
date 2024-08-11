class Solution {
public:
    int m[100003];
    void dfs(int node , vector<int>adj[]){
        // vis[node]=1;
        if(adj[node].size() == 0){
            m[node] = 1;
            return ;
        }
        int total = 0;
        for(auto it: adj[node]){
             dfs(it , adj);
            total+=m[it];
        }
        m[node] =  total+1;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        memset(m , 0 , sizeof(m));
        vector<int>adj[n];
        vector<int>store(n+1);
        for(auto it : edges){
            int a = it[0];
            int b = it[1];
            if(a == 0) adj[a].push_back(b);
            if(b==0) adj[b].push_back(a);
            if(store[a] ==1 ) adj[a].push_back(b);
            if(store[b] ==1) adj[b].push_back(a);
            store[a]= 1 , store[b]=1;
        }
        //
        vector<int>vis(n , 0);
        dfs(0 , adj );
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            int temp = -1;
            bool isEqual = true;
            for(auto it : adj[i]){
                if(temp == -1) temp = m[it];
                else if(temp != m[it]){
                    isEqual = false;
                }
            }
            if(isEqual== true) ans++;
        }
        return ans;
    }
};
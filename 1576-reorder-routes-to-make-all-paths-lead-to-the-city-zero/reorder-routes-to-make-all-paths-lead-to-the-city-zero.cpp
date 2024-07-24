class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int>dirAdj[n];
        for(auto it : connections){
            dirAdj[it[0]].push_back(it[1]);
        }
         vector<int>undirAdj[n];
         for(auto it : connections){
            undirAdj[it[0]].push_back(it[1]);
            undirAdj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n , 0 );
        queue<int>q;
        q.push(0);
        vis[0] =  1;
        int ans = 0 ;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it :undirAdj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    for(auto check : dirAdj[node]){
                        if(check == it) ans++;
                    }
                    q.push(it);       
                }
            }
        }
        return ans;
    }
};
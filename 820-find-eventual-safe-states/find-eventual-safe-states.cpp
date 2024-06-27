class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>adj[V];
        vector<int>inDegree(V,0);
        for(int i=0 ; i<V ; i++){
            // ith node 
            for(auto it : graph[i]){
                // it -> i
                adj[it].push_back(i);
                inDegree[i]++;
            }
        }
        // adjacency list created
        queue<int>q;
        vector<int>ans;
        for(int i=0 ; i<V ; i++){
            if(!inDegree[i]){
                // cout<<i<<endl;
                q.push(i);
            }
        }

        while(!q.empty()){
            int node  = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }


        // for(auto it : ans) cout<<it<<" ";
        sort(ans.begin(),ans.end());
        return ans;
    }
};
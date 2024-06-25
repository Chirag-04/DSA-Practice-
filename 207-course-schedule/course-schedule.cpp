class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& pre) {
        // it would be easy for us to deal with 
        vector<int>topo;
        vector<int>inDegree(V);
        vector<int>adj[V];
        queue<int>q;
        for(auto it : pre){
            int a = it[0];
            int b = it[1];
            // b->a
            adj[b].push_back(a);
            inDegree[a]++;
        }
        // created the adj list 
        for(int i=0 ; i<V ; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        // created 

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return topo.size()== V ? true : false;
    }
};
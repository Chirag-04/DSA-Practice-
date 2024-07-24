class Solution {
public:
    using pii = pair<int,pair<int,int>>;
    // dis , node , lastEdge
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int>redAdj[n];
        vector<int>blueAdj[n];
        for(auto it : redEdges){
            int n1 =  it[0];
            int n2 =  it[1];
            redAdj[n1].push_back(n2);
        }
        for(auto it : blueEdges){
            int n1 =  it[0];
            int n2 =  it[1];
            blueAdj[n1].push_back(n2);
        }
        queue<pii>q;
        vector<int>ans(n ,-1);
        vector<vector<bool>> vis(n, vector<bool>(3, false)); 
        vis[0][0] = true;
        vis[0][1] = true;
        vis[0][2] = true;
        q.push({0 , {0 , 0}});
        ans[0] = 0 ;

        // visted will tell that whether the next node is being ttdaversed iwth given color or not 

        while(!q.empty()){
            int dis = q.front().first;
            int node =  q.front().second.first;
            int last_edge_color = q.front().second.second;
            q.pop();
            if(last_edge_color != 1){
                for(auto next_node : redAdj[node]){
                    if(!vis[next_node][1]){
                        vis[next_node][1] = true;
                        if(ans[next_node] == -1) ans[next_node] = 1+dis;
                        else ans[next_node] =  min(ans[next_node] , 1+dis);
                        q.push({ 1+dis , {next_node , 1}});
                    }
                }
            }
            if (last_edge_color != 2) {
                for (auto next_node : blueAdj[node]) {
                    if (!vis[next_node][2]) {
                        vis[next_node][2] = true;
                        if (ans[next_node] == -1) {
                            ans[next_node] = dis + 1;
                        } else {
                            ans[next_node] = min(ans[next_node], dis + 1);
                        }
                        q.push({dis + 1, {next_node, 2}});
                    }
                }
            }
        }

        // for(int i=0; i<ans.size() ; i++){
        //     if(ans[i] == 1e9){
        //         ans[i] = -1;
        //     }
        // }
       return ans ;
    }
};
class Solution {
public:
    void bfs(int start , vector<int>&vis , vector<int>adj[] ,
    vector<int>&dis ){
        queue<pair<int,int>>q;
        q.push({start ,0});
        vis[start] = 1 ;
        dis[start] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    dis[it] = dist+1;
                    q.push({it , dist+1});
                }
            }

        }   
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int>adj[n];
        for(int i=0; i <edges.size() ; i++ ){
            // 
            if(edges[i]!=-1) adj[i].push_back(edges[i]);
        }
        // for(int i=0 ; i<n ; i++){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        vector<int>dis1(n  ,-1);
        vector<int>vis(n , 0);

        bfs(node1 , vis , adj  , dis1);
        for(auto it : dis1){
            cout<<it<<" ";
        }
        cout<<endl;
        

         vector<int>dis2(n  ,-1);
        vector<int>vis2(n , 0);
         bfs(node2 , vis2 , adj  , dis2);
         for(auto it : dis2){
            cout<<it<<" ";
        }

       int mini = INT_MAX;
        int index = -1;
        for (int i = 0; i < n; i++) {
            if(dis1[i] !=-1 and dis2[i]!=-1){
                int maxDis = max(dis1[i] , dis2[i]);
                if(maxDis < mini){
                    mini = maxDis;
                    index = i;
                }else if(maxDis == mini and i< index){
                    index = i ;
                }
            }
        }
        return index;
    }
};
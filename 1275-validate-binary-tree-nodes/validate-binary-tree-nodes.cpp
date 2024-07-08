class Solution {
public: 
    void dfs(int start  , vector<int>&visited , vector<int>adj[]){
        visited[start] = 1;
        for(auto it : adj[start]){
            if(!visited[it]){
                dfs(it , visited , adj);
            }
        }
    }
    bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rc) {
        // for a graph to be a binary tree 
        // is should follow three apporaches
        // 1 singe parent 
        // 2 single non parent node 
        // 3 connected 
        vector<int>parent(n,-1);
        for(int i=0 ; i<n ; i++){
            int l = lc[i];
            int r = rc[i];
            if(l!=-1){
                // i is the parent of l
                if(parent[l] == -1) parent[l] = i;
                else return false;
               
            }
            if(r!=-1){
                if(parent[r] ==-1) parent[r] = i;
                else return false;
            }

        }

        // for(auto it : parent){
        //     cout<<it<<" ";
        // }
        // cout<<endl;

        // second check 
        int root =-1;
        int ct = 0;
        for(int i=0 ; i<n ; i++){
            if(parent[i] == -1){
                ct++;
                root = i;
            }
        }
        if(ct !=1) return false;

         vector<int>adj[n];
        for(int i=0 ; i<n ; i++){
            int l = lc[i];
            int r = rc[i];
            if(l!=-1) adj[i].push_back(l);
            if(r!=-1) adj[i].push_back(r);
        }

        vector<int>visited(n);

        dfs(root , visited  , adj);
        for(auto it : visited){
            if(it == 0) return false;
        }
       return true;

    }
};
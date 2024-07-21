class Solution {
public:
    vector<int> topoSort(vector<int>adj[] ,  vector<int>&inDegree ){
        vector<int>ans;
        queue<int>q;
        for(int i=1 ; i<inDegree.size() ; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        //
        while(!q.empty()){
            int node =  q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        return ans ;
    }
    vector<vector<int>> buildMatrix(int k, 
    vector<vector<int>>& rowCond,
    vector<vector<int>>& colCond) {
        vector<vector<int>>ans(k , vector<int>(k , 0));

        vector<int>adj[k+1];
        vector<int>inDegree1(k+1);
        for(auto it :rowCond){
            int n1 = it[0];
            int n2 = it[1];
            // n1 -> n2
            adj[n1].push_back(n2);
            inDegree1[n2]++;
        }  
        vector<int>topo1 =  topoSort(adj , inDegree1);
        if(topo1.size() !=k) return {}; 
        for(int i=0 ; i<k ; i++){
            ans[i][0] =  topo1[i];
        }

        vector<int>adj2[k+1];
        vector<int>inDegree2(k+1);
        for(auto it :colCond){
            int n1 = it[0];
            int n2 = it[1];
            // n1 -> n2
            adj2[n1].push_back(n2);
            inDegree2[n2]++;
        }  


         vector<int>topo2 =  topoSort(adj2 , inDegree2);
        if(topo2.size() !=k) return {}; 

        vector<int>correct(k+1);
        for(int j=0 ; j<topo2.size() ; j++){
            correct[topo2[j]] = j;
        }

        // for(int i=0 ; i<correct.size() ; i++){
        //     cout<<i<<" "<<correct[i]<<endl;
        // }

        // for(int i=0 ; i<k ; i++){
        //     for(int j=0 ; j<k ; j++){
        //         cout<<ans[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0 ; i< k ; i++){
            int num = ans[i][0];
            int correct_place =  correct[num];
             swap(ans[i][0] , ans[i][correct_place]);
        }

        //   for(int i=0 ; i<k ; i++){
        //     for(int j=0 ; j<k ; j++){
        //         cout<<ans[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }


        return ans ;
    }
};
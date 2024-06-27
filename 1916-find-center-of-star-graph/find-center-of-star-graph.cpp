class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int>inDegree(edges.size()+2);
        int center = -1;
        for(auto it : edges){
            int a = it[0];
            int b = it[1];
            inDegree[a]++;
            inDegree[b]++;
            if(inDegree[a] ==edges.size()) center = a;
            if(inDegree[b] ==edges.size()) center = b;

        }
       return center;

    }
};
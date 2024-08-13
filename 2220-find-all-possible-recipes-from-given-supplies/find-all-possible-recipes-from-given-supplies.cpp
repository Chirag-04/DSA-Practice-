class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // more intuitive way of solving this is using graph 
        // as there is something before something pattern
        // so lets create the graph 
        unordered_map<string,int>inDegree;
        unordered_map<string  , vector<string>>adj; // for a reciepes all the ind require d
        for(int i=0 ; i<recipes.size() ; i++){
            string dish =  recipes[i];
            for(int j=0 ; j <ingredients[i].size() ; j++){
                // now for dish i need ingredients first 
                // it means edge from 
                string req =  ingredients[i][j];
                adj[req].push_back(dish);
                inDegree[dish]++;
            }
        }
        // now simple bfs traversal
        vector<string>ans;
        queue<string>q;
        for(auto it : supplies){
            q.push(it);
        }
        // 
        while(!q.empty()){
            string str = q.front();
            q.pop();
            for(auto it: adj[str]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    ans.push_back(it);
                    q.push(it);
                }
            }
        }
        return ans ;
    }
};
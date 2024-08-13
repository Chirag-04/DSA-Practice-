class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string>s;
        for(auto it : supplies) s.insert(it);
        vector<string>ans;
        // we will stop when all teh items that could be made are present in set oly
        bool finalCheck = true;
        while(finalCheck){
            // lets iterate over the recipes
            finalCheck = false;
            for(int i =0 ; i <recipes.size(); i++){
                // for second or further pass i need to check all the ing again 
                if(s.contains(recipes[i])) continue;
                //it will directly get returned from here 
                // i will check wehtehr i will be able to create the dish or not 
                bool allPresent = true;
                for(auto it : ingredients[i]){
                    string req =  it;
                    if(!s.contains(req)){
                        allPresent = false;
                    }
                }
                // if allPresent is false it measn i wont be able to make right now 
                if(allPresent){
                    finalCheck = true;
                    ans.push_back(recipes[i]);
                    s.insert(recipes[i]);
                }
            }
        }
        return ans ;
    }
};
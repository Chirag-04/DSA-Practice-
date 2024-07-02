class Solution {
public:
    // since it is not an optimization problem 
    // we have to find the total possible combinations
    // so we will use the backtracking step
    vector<vector<int>> ans ;
    void f(int i ,  int x , vector<int>& cand , vector<int>&temp){
        if(x < 0) return ;
        if(i ==  cand.size()) return ;
        // cout<<"hi"<<endl;
        if(x  ==  0){
           
            ans.push_back(temp);
            return ;
        }
        // pick the current element 
         
        temp.push_back(cand[i]);
        f(i , x-cand[i] , cand , temp);
        // not pick the currnet element 
        temp.pop_back();
        f(i+1 , x , cand , temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
         f(0 , target ,  candidates, temp);
         return ans ;
    }
};
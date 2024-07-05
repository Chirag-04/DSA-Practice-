class Solution {
public:
    vector<vector<int>>ans;
    int n;
    void f(int i , int  x , vector<int>&cand , vector<int>&temp){
        if(x == 0 ){
            ans.push_back(temp);
            return ;
        }
        if(i >=n){
            return;
        }
        if(x < 0) return ;
       
        //pick the current element 
        temp.push_back(cand[i]);
        f(i+1 , x-cand[i] ,cand , temp);

        // not pick the current element 
        temp.pop_back();
        while(i+1<n and cand[i] == cand[i+1]) i++; 
        f(i+1 , x , cand , temp);

    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int x) {
        // first of all let sort the array so thaat all the duplicates comes together
        n = cand.size();
        sort(cand.begin() , cand.end());
        vector<int>temp;
        f(0  , x , cand , temp);
        return ans ;
    }
};
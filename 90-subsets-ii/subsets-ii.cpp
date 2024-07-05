class Solution {
public:
   vector<vector<int>>ans;
   set<vector<int>>s;
  void f(int i  , vector<int>&temp ,vector<int>& nums ){
    if(i >= nums.size()){
        ans.push_back(temp);
        return ;
    }
    // take the element 
    temp.push_back(nums[i]);
    f(i+1 , temp , nums);
    // not take the elemtn 

    temp.pop_back();
    //so if i decided not to take a particular index 
    // then i should ignore it's all occurences 
    while(i+1<nums.size() and nums[i] == nums[i+1]) i++;
    f(i+1 , temp , nums);
  }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // they want in the sorted order 
        // first using set data structure 
        sort(nums.begin() , nums.end());
        vector<int>temp;
        f(0  , temp , nums);
        // for(auto it : s){
        //     ans.push_back(it);
        // }
        return ans ;
    }
};
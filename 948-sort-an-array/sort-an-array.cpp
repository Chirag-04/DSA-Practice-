class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
      // lots of sorting tech
      // let uuse any one of them 
      priority_queue<int>pq;
      for(auto it : nums) pq.push(it);
      vector<int>ans(nums.size());
      for(int i=nums.size()-1 ; i>=0 ; i--){
        ans[i] = pq.top();
        pq.pop();
      }  
      return ans;
    }
};
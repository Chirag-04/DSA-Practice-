class Solution {
public:
   using pii = pair<int,int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // brute force 
        unordered_map<int,int>m;
        for(auto it : nums) m[it]++;
        priority_queue<pii>pq;
        for(auto it : m){
            pq.push({it.second , it.first});
        }
        vector<int>ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans ;
    }
};
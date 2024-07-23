class Solution {
public:
// we can make use of custom comparator 
//  lamda expression
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(auto it: nums){
            m[it]++;
        }
        //
        sort(nums.begin() , nums.end() , [&m](int a , int b){
            // a b 
            if(m[a] != m[b]) return m[a] < m[b];
            else  return (a > b);
        });
        return nums;
    }
};
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>m;
        int count = 0 ;
        int sum = 0 ;
        for(int i=0 ; i<n ; i++){
            if(nums[i] % 2 != 0) sum++;
            if(sum == k) count++;
            if(m.find(sum -k)!=m.end()){
                count+=m[sum-k];
            }
            m[sum]++;
        }
        return count;
    }
};
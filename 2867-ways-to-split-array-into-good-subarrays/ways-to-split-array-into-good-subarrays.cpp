class Solution {
public:
    const int mod =  1e9+7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        unordered_map<int,int>m;
        int n = nums.size();
        int count_1 = 0;
        for(int i=0 ; i<n ; i++){
            if(nums[i] == 1) count_1++;
        }
        if(count_1== 0) return 0;
        long long ans = 1;
        for(int i=0 ; i<n ; i++){
            if(nums[i] == 1){
                if(m.find(nums[i])!=m.end()){
                    ans = ((ans)%mod*(i-m[nums[i]]))%mod;
                }
            }
            if(nums[i] == 1 ){
                m[nums[i]] = i ;
            }
        }

        return ans ;
    }
};
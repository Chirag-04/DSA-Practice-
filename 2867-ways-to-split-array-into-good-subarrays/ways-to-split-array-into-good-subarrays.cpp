class Solution {
public:
    const int mod =  1e9+7;
    // can we reomve extra spcae 
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int map = -1 ;
        int n = nums.size();
        int count_1 = 0;
        for(int i=0 ; i<n ; i++){
            if(nums[i] == 1) count_1++;
        }
        if(count_1== 0) return 0;
        long long ans = 1;
        for(int i=0 ; i<n ; i++){
            if(nums[i] == 1){
                if(map!=-1){
                    ans = ((ans)%mod*(i-map))%mod;
                }
            }
            if(nums[i] == 1 ){
                map = i ;
            }
        }

        return ans ;
    }
};
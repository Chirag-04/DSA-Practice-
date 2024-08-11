class Solution {
public:
    int dp[2002][53][53];
    int mod = 1e9+7;
    int f(int i , int prev1 , int prev2 , vector<int>&nums){
        if(i == nums.size()){
            return 1;
        }
        if(dp[i][prev1][prev2]!=-1) return dp[i][prev1][prev2];
        int sum = nums[i];
        int pairs = 0;
        for(int j=0;  j<=sum ; j++){
            if(j>= prev1 and prev2 >= sum-j){
                pairs =( pairs + f(i+1 , j , sum-j , nums))%mod;
            }
        }
        return dp[i][prev1][prev2] = (pairs)%mod;
    }
    int countOfPairs(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp));
        return (f(0 , 0, 51  , nums))%mod;
    }
};
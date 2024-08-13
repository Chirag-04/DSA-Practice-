class Solution {
public:
    int n ;
    int dp[502][502];
    int f(int i , int val  , vector<int>&sat){
        if(i == sat.size()) return 0;
        if( dp[i][val]!= -1) return  dp[i][val];
        int pick =  (sat[i]*val)+f(i+1 , val+1 , sat);
        int not_pick = 0 + f(i+1 ,val , sat);
        return dp[i][val] =max(pick , not_pick);
    }
    int maxSatisfaction(vector<int>& sat) {
        memset(dp , -1 , sizeof(dp));
        n = sat.size();
        sort(sat.begin()  ,sat.end());
        return f(0 , 1 ,sat);
    }
};
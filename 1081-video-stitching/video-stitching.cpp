class Solution {
public:
    int dp[102][102];
    int f(int i ,int tm ,  vector<vector<int>>& clips, int time ){
        if(tm >= time) return 0;
        if(i == clips.size()) return 110;
        if(tm < clips[i][0]){
            return 110;
        }
        if(dp[i][tm] !=-1) return dp[i][tm];
        int pick = 1 + f(i+1 , max(tm , clips[i][1]) , clips  , time);
        int not_pick  = f(i+1 , tm  , clips  , time);

        return dp[i][tm] = min(pick , not_pick);
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        // n = clips.size();
        sort(clips.begin() , clips.end());
        memset(dp , -1 , sizeof(dp));
        if(clips[0][0] !=0) return -1;
        int ans = f(0 ,0 ,clips , time);
        return ans>=110 ? -1 : ans;
    }
};
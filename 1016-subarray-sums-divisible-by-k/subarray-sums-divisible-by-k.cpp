class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans  = 0 ;
        int sum = 0 ;
        unordered_map<int,int>m;
        for(int i=0 ; i<n ;i++){
            sum+=nums[i];
            if(sum%k == 0) ans++;
            int rem  = sum%k;
            if(rem < 0) rem+=k;
            if(m.find(rem)!=m.end()){
                ans+=m[rem];
            }
            m[rem]++;
        }
        return ans ;
    }
};
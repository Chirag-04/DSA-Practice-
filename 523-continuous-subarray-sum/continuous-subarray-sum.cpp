class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>m;
        int sum = 0 ;
        for(int i=0; i <n ; i++){
            sum+=nums[i];
            if(sum%k==0 and i>=1) return true ;
            int rem = sum % k;

            if(m.find(rem)!=m.end()){
                if(i - m[rem] >=2 ) return true;
            }
            else{
                m[rem] = i;
            }
        }
        return false;
    }
};
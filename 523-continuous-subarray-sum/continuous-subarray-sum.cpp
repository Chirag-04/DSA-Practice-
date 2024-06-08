class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n = nums.size();
        int sum = 0 ;
        for(int i=0; i<n ;i++){
            sum+=nums[i];
            if(i>=1 and (sum%k == 0)){
                return true;
            } 
            
            int diff = sum %k; // 29/6 -> 
            for(int num = diff ; num <sum ; num+=k){
                if(m.count(num)) {
                    if(i-m[num] >=2) {
                        cout<<2<<endl;
                        return true;
                    }
                }
            

       }
           
            if(!m.count(sum)){
                m[sum] = i;
            }
        } 
        for(int i=1 ; i<n ; i++){
            if(nums[i] ==0 and nums[i-1]==0) return true;
        } 
        return false;
    }
};
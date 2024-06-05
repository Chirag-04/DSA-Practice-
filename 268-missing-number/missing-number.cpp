class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // if i == nums[i] i++
        // pos i++
        // 
        int n = nums.size();
        int i=0 ;
        int ans =  n;
        while(i < n ){
            int pos = nums[i];
            if(pos>=n or i==nums[i]  ) i++;
            else{
                swap(nums[i]  , nums[pos]);
            }
        }
        for(auto it :nums) cout<<it<<" ";
        for(int j=0; j<n ;j++){
            if(nums[j]!=j){
                ans =  j;
                break;
            }
        }
        return ans ;
    }
};
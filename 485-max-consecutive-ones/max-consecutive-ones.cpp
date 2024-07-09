class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = 0 ;
        int i= 0 ;
        int j = 0 ;
        int n = nums.size();
        while(j<n){
            if(nums[i] ==1 and nums[j] == 1){
                len  = max(len , j-i+1);
                j++;
            }
            else{
                j++;
                i=j;
            }
        }
        return len ;
    }
};
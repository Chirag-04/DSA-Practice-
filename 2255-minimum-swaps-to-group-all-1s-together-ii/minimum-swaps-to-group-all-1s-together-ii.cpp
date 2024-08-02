class Solution {
public:
    int minSwaps(vector<int>& num) {
        int n = num.size();
        int count_1 = 0;
        for(auto it : num){
            if(it == 1) count_1++;
        }
        //
        vector<int>nums = num;
        for(auto it: num){
            nums.push_back(it);
        }
        if(count_1 ==0) return 0;
        cout<<count_1<<endl;
        for(auto it : nums) cout<<it<<" ";
        int i=0  , j=0 , ans = nums.size();
        int ct = 0;
        while(j <nums.size() ){
            if(nums[j] == 1) ct++;
            if(j-i+1 < count_1){
                j++;
            }
            else if(j-i+1){
                int count_0 = j-i+1-ct;
                ans = min(count_0 , ans);
                if(nums[i] == 1) ct--;
                i++,j++;
            }
          
    }
      return ans ;
    }
};
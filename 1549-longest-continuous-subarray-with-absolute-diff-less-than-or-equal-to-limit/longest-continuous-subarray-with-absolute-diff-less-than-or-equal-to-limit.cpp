class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int>maxQ;
        deque<int>minQ;
       int i= 0 , j= 0 ;
       int ans  = 0;
       while(j< n ){
        // if(nums[j] <= limit) ans= max(ans , j-i+1);

        while(!maxQ.empty() and maxQ.back() < nums[j]) maxQ.pop_back();
        maxQ.push_back(nums[j]);

        while(!minQ.empty() and minQ.back() >  nums[j]) minQ.pop_back();
        minQ.push_back(nums[j]);

        if(maxQ.front() - minQ.front() <= limit){
            ans = max(ans , j-i+1);
            j++;
        }
        else{
            if(maxQ.front() == nums[i]) maxQ.pop_front();
            if(minQ.front() == nums[i]) minQ.pop_front();
            i++;
            j++;
        }

       }
       return ans ;
    }
};
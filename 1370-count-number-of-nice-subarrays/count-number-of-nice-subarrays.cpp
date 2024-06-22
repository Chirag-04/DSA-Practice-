class Solution {
public:
    int numberOfSubarrays(vector<int>& v, int k) {
        vector<int>nums;
        for(int i=0 ; i<v.size() ; i++){
            if(v[i] % 2 != 0) nums.push_back(1);
            else nums.push_back(0);
        }
        // now this problem is reduced to prefix su
        unordered_map<int,int>m;
        int count = 0 ;
        int sum = 0 ;
        // vector<int>prefix(nums.size());
        // prefix[0] = nums[0];
        // for(int i=1 ; i<nums.size() ; i++){
        //     prefix[i] = nums[i] + nums[i-1];
        // }

        for(int i=0 ; i<nums.size() ; i++){
           sum+=nums[i];
           if(sum==k) count++;
           // if sum ==k  then also increase the counter 
           
            if(m.find(sum- k) != m.end() ){
                //count+=1; // absolutely not
                count+=m[sum-k];
            }
           m[sum]++;

        }
       
        
   return count ;




    }
};
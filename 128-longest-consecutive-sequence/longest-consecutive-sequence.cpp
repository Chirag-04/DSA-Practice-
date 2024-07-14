class Solution {
public:
    // method 1 sort the array and keep on builidig the sequence
    int longestConsecutive(vector<int>& nums) {
      int n =  nums.size();
      set<int>s;
      for(int i=0 ; i<n ; i++){
        s.insert(nums[i]);
      }
      int len  = 1;
      int ans = 0;
      bool firsTime = true;
      int prev;
      for(auto it : s){
        if(firsTime){
            prev = it;
            firsTime=!firsTime;
        }
        else{
            if(it == prev+1){
                len++;
                prev = it;
            }
            else{
                len = 1;
                prev = it;
            }
        }
        ans  = max(ans , len);
        cout<<"ans"<<" "<<ans<<endl;
      }
     return ans ;
    }
};
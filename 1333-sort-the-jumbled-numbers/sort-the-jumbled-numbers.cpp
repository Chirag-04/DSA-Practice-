class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>>ans;
        for(int i=0 ; i<nums.size() ; i++){
            int num =  nums[i];
            int new_no = 0 ;
            int expo =  0;
            while(num >0){
                int mod =  num%10;
                num = num/10;
                new_no += mapping[mod]*pow(10  ,expo);
                expo++;
            }
            if(nums[i] == 0) new_no = mapping[0];
            cout<<num<<endl;
            ans.push_back({new_no , i}); 
        }
        sort(ans.begin() , ans.end());
        vector<int>final;
        for(auto it : ans){
            final.push_back(nums[it.second]);
        }
        return final;
    }
};
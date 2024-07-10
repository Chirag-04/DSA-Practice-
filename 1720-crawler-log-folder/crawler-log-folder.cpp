class Solution {
public:
    int minOperations(vector<string>& s) {
        int ans = 0 ;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i].substr(0 , 2) == "./"){
                // current 
                continue;
            }
             if(s[i].substr(0 , 3) == "../"){
                // parent 
                if(ans>0)ans--;
            }
            else{
                // child
                ans++;
            }
        }
       return ans;
    }
};
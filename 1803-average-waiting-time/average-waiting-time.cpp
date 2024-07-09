class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) {
        int start =  0;
        int n = cust.size();
        long ans  = 0 ;
        for(int i=0 ; i<n ; i++){
            if(start < cust[i][0]){
                start = cust[i][0]; //1
            }
            int end =  start+cust[i][1]; //3
            ans+=(end-cust[i][0]);
            start =  end; //3
        }
        double final =  (double)ans/n;
        return final;
    }
};
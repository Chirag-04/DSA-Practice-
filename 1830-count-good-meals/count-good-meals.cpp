class Solution {
public:
    int mod =  1e9+7;
    int countPairs(vector<int>& del ) {
        int n = del.size();
        unordered_map<int,int>m;
        vector<int>power(22);
        
        int ans  = 0 ;
        for(int i=0; i <22 ; i++) power[i] = pow(2 , i);

        for(int i=0; i <n ; i++){

            for(int j=0 ; j<22 ; j++){
                int a = del[i];
                // a + b =  power[i]
                int b = power[j] - a;
                if(m.count(b)){
                    ans= (ans+m[b])%mod;
                }
            }
            m[del[i]]++;
        }
        return ans ;
    }
};
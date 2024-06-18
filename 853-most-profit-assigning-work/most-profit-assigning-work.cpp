class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& pro, vector<int>& wk) {
        int total = 0 ;
        int j = 0 ;
        vector<pair<int,int>>v;
        for(int i=0; i<diff.size(); i++){
            v.push_back({diff[i] , pro[i]});
        }
        int ans = 0 ;
        sort(v.begin() , v.end());
        int wk_profit = 0;
        sort(wk.begin() , wk.end());
        for(int i=0; i <wk.size() ; i++){
            int ability = wk[i];
            while(j<v.size()){
                if(ability>= v[j].first){
                    wk_profit =  max(wk_profit , v[j].second);
                    j++;
                }
                else break;
            }
            ans+=wk_profit;
        }
        return ans ;
    }
};
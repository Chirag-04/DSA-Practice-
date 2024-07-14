class Solution {
public:
    using ll =long long;
    using pii = pair<ll , pair<ll,ll>>;
    long long minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
        vector<pii>ans;
        for(int i=0 ; i<hc.size(); i++){
            ans.push_back({hc[i] , {i  , 1}});
        }
        for(int i=0 ; i<vc.size(); i++){
            ans.push_back({vc[i] , {i  , 0}});
        }
        sort(ans.begin() , ans.end() , greater<pii>());

        ll h =1 , v = 1;
        ll final = 0;
        for(int i=0 ; i<ans.size() ; i++){
            if(ans[i].second.second == 1){
                final+=(ans[i].first *  v);
                h++;
            }else{
                final+=(ans[i].first * h);
                v++;
            }
        }
       return final;
    }
};
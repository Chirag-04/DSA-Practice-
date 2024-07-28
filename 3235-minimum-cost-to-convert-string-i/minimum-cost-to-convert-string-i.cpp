class Solution {
public:
    using ll = long long ;
    ll minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        ll n = original.size();
      vector<vector<ll>>store(26 , vector<ll>(26 , INT_MAX));
      // since there could be mutiple instances of a->b
      for(int i=0 ; i<n ; i++){
        ll ch1 = original[i] -'a';
        ll ch2 = changed[i] -'a';
        store[ch1][ch2] = min(store[ch1][ch2] ,(ll)cost[i] ); 
      }  
      for(int i=0;  i<26 ; i++) store[i][i] = 0;
      // floyd warshall
      for(int via = 0; via<26 ; via++){
        for(int i=0; i <26 ; i++){
            for(int j=0; j <26 ; j++){
                if(store[i][via]!=INT_MAX and store[via][j]!=INT_MAX){
                    store[i][j] = min(store[i][j] , store[i][via] + store[via][j]);
                }
            }
        }
      }
      //
      ll final_cost  = 0;
      for(int i=0 ; i<source.size() ; i++){
           int ch1 =  source[i] -'a';
           int ch2 =  target[i] - 'a';
           if(store[ch1][ch2]==INT_MAX ) return -1;
           final_cost+=store[ch1][ch2];
      }
      return final_cost;
    }
};
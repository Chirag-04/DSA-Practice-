class Solution {
public:
    using ll =long long ;
    // guy whose degree is high assign with greatest value 
    long long maximumImportance(int n, vector<vector<int>>& roads) {
      unordered_map<int,int>m;
      for(auto it : roads){
        int a = it[0];
        int b = it[1];
        m[a]++,m[b]++;
      } 
      priority_queue<pair<int,int>>pq;
      for(auto it : m){
        pq.push({it.second , it.first});
      }
      vector<int>values(n);
      int x = n;
      while(!pq.empty()){
        int node  = pq.top().second;
        values[node] = x;
        x--;
        pq.pop();
      }
      ll ans  = 0 ;
      for(auto it : roads){
        int a =  it[0];
        int b = it[1];
        ans+=values[a]+values[b];
      }

      return ans ;
    }
};
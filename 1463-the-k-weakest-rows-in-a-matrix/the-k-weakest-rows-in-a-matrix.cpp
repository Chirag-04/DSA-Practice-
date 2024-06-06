class Solution {
public:
   // approach 1 : use simple brute force
   // anything realted to sorted => binary
   int findOne(vector<vector<int>>& mat , int i ){
      int lo = 0 ;
      int hi = mat[i].size()-1;
      int ans = -1;
      while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(mat[i][mid] ==1 ){
            ans =  mid;
            lo =  mid+1;
        }
        else {
            hi = mid-1;
        }
      }
      return ans ;
   }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // can be solved using min heap
        int n = mat.size();
        vector<pair<int,int>>v;
        for(int i=0; i<mat.size(); i++){
            int ct  =  findOne(mat , i);
            if(ct<0)ct=0;
            else ct++;
            v.push_back({ct , i});
        }
        sort(v.begin() , v.end());
        vector<int> ans;
        for(int i=0; i<k ;i++){
            ans.push_back(v[i].second);
        }
        return ans ;
    }
};
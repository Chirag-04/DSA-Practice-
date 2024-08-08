class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int n, int m, int i, int j) {
        int count  = n*m;
        int total =1 ;
        vector<vector<int>>ans;
        ans.push_back({i , j});
         if(total == count ) return ans;
        int x = 1;
        while(1){
            // cout<<"x"<<x<<" "<<i<<" "<<j<<endl;
            int right =  x , down =x , left = x+1 , up = x+1;
            bool check = false;
            int r = j;
            while(right--){
                r= r+1;
                //  cout<<i<<" "<<r<<endl; 
               if(i>=0 and i<n and r>=0 and r<m) {
             total++;  
             ans.push_back({i , r});
              if(total == count ) {
                check = 1;
                break;
              }
               }
            }
            if(check) break;
            j = r;
            int d = i;
            while(down--){
                d= d+1;
                //  cout<<d<<" "<<j<<endl;
                if(d>=0 and d<n and j>=0 and j<m) {
                total++; 
                ans.push_back({d , j});
               if(total == count ) {
                check = 1;
                break;
              }
                }
            }
               if(check) break;
            i = d;
            int l = j;
            while(left--){
                l = l-1;
            //  cout<<i<<" "<<l<<endl; 
              if(i>=0 and l>=0 and i<n and l<m)  {
             total++; 

             ans.push_back({i , l}); 
             if(total == count ) {
                check = 1;
                break;
              } 
              }
            }
               if(check) break;
            j= l;
            int u =  i;
            while(up--){
                u = u-1;
                // cout<<u<<" "<<j<<endl;
                if(u>=0 and j>=0 and u<n and j<m) {
                total++; 

                ans.push_back({u , j}); 
                if(total == count ) {
                check = 1;
                break;
              }  
                }
            }
               if(check) break;
            i= u;
            x=x+2;
        }
        cout<<i<<" "<<j<<endl;
        return ans ;
    }
};
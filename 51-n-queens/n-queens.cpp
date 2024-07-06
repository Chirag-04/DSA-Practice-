class Solution {
public: 
     vector<vector<string>>ans;
    void f(int i , vector<int>&col , vector<int>&diag , 
    vector<int>&revDiag , vector<vector<int>>&vis , int n , vector<string>&temp){
        if(i>=n){
            ans.push_back(temp);
            return ;
        }
        // choose the column 
        for(int j=0 ; j<n ; j++){
            if(!vis[i][j] and !col[j] and !diag[i+j] and !revDiag[(n-1)-(j-i)]){
                // we can choose this path
                vis[i][j] = 1;
                col[j] = 1;
                diag[i+j] =1; 
                revDiag[(n-1)-(j-i)] = 1;
                string s(n , '.');
                s[j] = 'Q';
                temp.push_back(s);
                f(i+1 , col , diag , revDiag , vis , n , temp);

                // undo the changes
                temp.pop_back();
                vis[i][j] = 0;
                col[j]  = 0;
                diag[i+j] =0; 
                revDiag[(n-1)-(j-i)] = 0;
                
            } 
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>temp;
        vector<int>col(n , 0);
        vector<int>diag(2*n-1 , 0);
        vector<int>revDiag(2*n-1 , 0);
        // now let say in one backteakcing step i have tried placing my queen at some particular cell let say 
        //i , j so should i call it again 
        // obc not 
        vector<vector<int>>vis(n , vector<int>(n ,0));
        // vector<string>temp;
        f(0 , col ,diag , revDiag , vis , n  , temp);
        return ans ;   
      
    }
};
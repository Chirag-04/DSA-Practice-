class Solution {
public:
    int dp[1001][1001];
    int f(int i , int rem , int maxh , int n , int W ,vector<vector<int>>& books){
        if(i>=n) return maxh;
        // keep the book
        // skip the book 
        if(dp[i][rem]!=-1) return dp[i][rem];
        int keep= INT_MAX , skip= INT_MAX;
        if(rem >= books[i][0]){
            keep =  f(i+1 , rem-books[i][0] , max(maxh ,books[i][1]) , n , W , books);
        }
        skip =  maxh + f(i+1 , W-books[i][0] , books[i][1]  , n , W  , books);

        return  dp[i][rem]= min(skip  , keep);
    }
    int minHeightShelves(vector<vector<int>>& books, int W) {
        memset(dp , -1 , sizeof(dp));
        return f(0 , W , 0 , books.size() , W , books);
    }
};
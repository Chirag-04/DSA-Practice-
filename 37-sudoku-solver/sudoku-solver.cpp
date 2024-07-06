class Solution {
public:
    bool isValid(int r, int c   , vector<vector<char>>& board , char ch ){

            for(int j =0 ;j< 9 ;j++){
                if(board[r][j] == ch) return false;
            }
            for(int i= 0 ; i<9 ; i++){
                if(board[i][c] == ch) return false;
            }
            int newr = r - (r%3);
            int newc = c - (c %3);
            for(int p =0 ; p<3  ; p++){
                for(int q =  0 ; q<3 ; q++){
                    if( board[newr + p][newc + q] == ch  ) return false;
                }
            }
            return true;
    }
    bool solve(vector<vector<char>>& board){
          for(int i= 0 ; i<9 ; i++){
            for(int j=0 ; j<9 ; j++){
                if(board[i][j] == '.'){
                    for(char ch = '1' ; ch<='9'; ch++){
                        if(isValid(i , j , board , ch)){
                            board[i][j] = ch;
                            // i have to check whether it is correct or not
                            bool isthisRight =  solve(board);
                            if(isthisRight) return true;
                            else {
                                // undo the step
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board){
        solve(board);
    }  
};
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board , 0 , 0);
    }
    bool solve(vector<vector<char>>& board , int row , int col){
        if(row == 9) return true;
        if(col == 9) return solve(board , row + 1 , 0);
        if(board[row][col] != '.') return solve(board , row , col+1);
        for(char c = '1' ; c<='9'; c++){
            if(isValid(board , row , col , c)){
                board[row][col] = c;
                if (solve(board , row , col+1)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    bool isValid(vector<vector<char>>& board , int row , int col , char c){
        for(int i=0; i<9; i++){
            if(board[row][i] == c) return false;
            if(board[i][col] == c) return false;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
        }
        return true;
    }
};
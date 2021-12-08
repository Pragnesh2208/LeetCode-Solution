/************************************Optimal Approch for Sudoku Solver*****************************************/
class Solution {
    private:
    bool solve(vector<vector<char>> & board) {
        for(int i = 0 ; i< 9 ; i++) {
            for(int j = 0 ; j < 9 ;j++) {
                if(board[i][j] == '.') {
                    for(char dig = '1' ; dig <= '9' ; dig++  ) {
                    if(isValid(board , i , j , dig)) {
                        board[i][j] = dig;
                        if(solve(board))
                            return true;
                        else{
                            board[i][j]='.';
                            }
                        }
                    }
                return false;
                }     
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board , int row , int col , char dig ) {
        for(int i = 0 ; i < 9 ; i++ ) {
            if(board[row][i] == dig ||board[i][col] == dig )
                return false;
            if( board[3 * (row/3) + i / 3] [ 3 * (col/3) + i %3] == dig )
                return false;   
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
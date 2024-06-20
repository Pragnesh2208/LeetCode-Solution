/** 
 * Optimal solution for N-Queen problem.
 * Time Complexity = O(N! + S(N)*N^2) = O(N!). Here S = solution and S(N) = we have n solutions.
 * Space Complexity = O(N).
*/
class Solution {
    bool getSolution(int row , int col , vector<string>&board , vector<vector<string>>&ans) {
        int boardSize = board.size();
        if(col == boardSize ) {
            ans.push_back(board);
            return true;
        }
        bool flag = false;
        for(int rowIndex = row ; rowIndex < boardSize ; rowIndex++) {
            if(isValidCell(rowIndex , col , board)) {
                board[rowIndex][col] = 'Q';
                if(getSolution(0 , col + 1 , board , ans)) {
                    flag = true;
                }
                board[rowIndex][col] = '.';
            }
        }

        return flag;
        
    }

    bool isValidCell(int row , int col , vector<string>&board) {
        int n = board.size();
        for(int i = 0; i < col ; i++) {
            if(board[row][i] == 'Q') return false;
        }

        for(int i = col -1 , j = row - 1 ; i >= 0  && j >= 0 ; i-- , j--) {
            if(board[j][i] == 'Q') return false;
        }

        for(int i = col -1 , j = row + 1 ; i >= 0  && j < n ; i-- , j++) {
            if(board[j][i] == 'Q') return false;
        }

        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string emptyRow(n , '.');
        vector<string>board(n , emptyRow);
        getSolution(0, 0 ,board , ans );
        return ans;
    }
};
/*****************************Optimal solution of Find Surrounded Regions**************************/
/****************************Time Complexity = O( V + E)*******************************************/
/***************************Space Complexity = O(max(row , col)) as of dfs*************************/
class Solution {
    void dfs(int i , int j , int &row , int &col , vector<vector<char>>&board){
        if(i< 0 || i == row || j < 0 || j == col || board[i][j] == 'X' || board[i][j] == 'b'){
            return ;
        }
        
        board[i][j] = 'b';

        dfs(i - 1 , j , row , col , board);
        dfs(i + 1 , j , row , col , board);
        dfs(i , j - 1 , row , col , board);
        dfs(i , j + 1 , row , col , board);
    }
   
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
 
        for(int i = 0 ; i < row ; i++ ){
            for(int j = 0 ; j < col ; j++){
                if(board[i][j] == 'O' && (i == 0 || i == row- 1 || j == 0 || j == col - 1) )
                    dfs(i , j , row, col , board);
            }
        }
        
        for(int i = 0 ; i < row ; i++ ){
            for(int j = 0 ; j < col ; j++){
                cout<<board[i][j]<<" ";
                if(board[i][j] == 'b')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
            cout<<endl;
        }
    }
};
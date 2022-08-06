/*****************************Optimal solution of Find Number of Enclaves**************************/
/****************************Time Complexity = O( V + E)*******************************************/
/***************************Space Complexity = O(V + E) as of dfs**********************************/
class Solution {
    void dfs(int i , int j , int &row , int &col , vector<vector<int>>&grid){
        if(i < 0 || i == row  || j < 0 || j == col ||grid[i][j] == 0 || grid[i][j] ==-1)
            return;
        grid[i][j] = -1;
        dfs(i - 1 , j , row, col , grid);
        dfs(i + 1 , j , row , col , grid);
        dfs( i , j + 1 , row ,col , grid);
        dfs( i ,j - 1 , row , col ,grid);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
       
        for(int i = 0 ; i < row ; i++)
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] == 1 && (i == 0 || j==0 || i == row - 1 || j == col -1))
                    dfs(i , j , row, col, grid);
            }
        int count = 0;
        for(int i = 0 ; i < row ; i++ ){
            
             for(int j = 0 ; j  <col ; j ++){
               
                if(grid[i][j] == -1)
                    grid[i][j]=1;
                else if(grid[i][j] == 1)
                    count++;
            }
        }
           
        return count;
    }
};
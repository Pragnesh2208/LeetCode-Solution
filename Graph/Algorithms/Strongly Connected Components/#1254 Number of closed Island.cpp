/*****************************Optimal solution to find Number of Closed Island**************************/
/****************************Time Complexity = O( V + E)*******************************************/
/***************************Space Complexity = O(V + E) as of dfs**********************************/
class Solution {
    private:
    void dfs(int i , int j , int &row , int &col , vector<vector<bool>>&visit , vector<vector<int>>&grid){
        if(i < 0 || i==row || j < 0 || j == col ||visit[i][j] == true || grid[i][j] == 1)
            return;
        visit[i][j] = true;
        dfs(i - 1 , j , row, col , visit , grid);
        dfs(i , j - 1 , row, col , visit , grid);
        dfs(i + 1 , j , row, col , visit , grid);
        dfs(i , j + 1 , row, col , visit , grid);
        
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0 ;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>>visit(row , vector<bool>(col , false));
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(visit[i][j] == false && (i== 0|| j==0|| i ==row- 1 || j == col - 1)){
                    dfs(i , j , row , col , visit , grid);
                }
            }            
        }
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(visit[i][j] == false && grid[i][j]==0){
                    dfs(i , j , row , col , visit , grid);
                    count++;
                }
            }            
        }
        
        return count;
    }                
};
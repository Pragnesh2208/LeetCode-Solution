/*****************************Optimal solution of Find Surrounded Regions**************************/
/****************************Time Complexity = O( V + E)*******************************************/
/***************************Space Complexity = O(V + E) as of Visit and dfs************************/
class Solution {
    
    int dfs(int i , int j , vector<vector<bool>>&visit , vector<vector<int>>&grid , int &row , int &col ){
        if(i < 0 || i == row || j < 0 || j == col || grid[i][j] == 0 || visit[i][j] == true) return 0;
        visit[i][j] = true;
       return  (1 +   dfs(i - 1 , j , visit , grid , row , col )+
        dfs(i , j + 1 , visit , grid , row , col)+
        dfs(i + 1 , j , visit , grid , row , col)+
        dfs(i , j - 1 , visit , grid , row , col));
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visit(row , vector<bool>(col , false));
        int ans = 0;
        for(int i = 0 ; i < row ; i++)
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] == 1)
               ans = max(ans , dfs( i , j , visit , grid, row , col)) ;
            }
        return ans;
    }
};
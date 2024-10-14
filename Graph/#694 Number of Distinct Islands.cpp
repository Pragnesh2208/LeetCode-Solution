/**
 * Optimal Solution for Number of Distinct Islands
 * Time Complexity = O(N * M)
 * Space Complexity = O(N * M)
 */
class Solution {
    private:
    void dfs(int row , int col , vector<vector<int>>&grid , vector<vector<bool>>&visited , vector<pair<int,int>>&path , int &row0 , int col0) {
        int totalRow = grid.size();
        int totalCol = grid.back().size();

        if(row < 0 || row >= totalRow 
        || col < 0 || col >= totalCol || visited[row][col] || grid[row][col] == 0)
            return;
        path.push_back({row - row0 , col - col0});
        visited[row][col] = true;
        dfs(row - 1 , col , grid, visited, path , row0 , col0);

        dfs(row , col - 1 , grid, visited, path , row0 , col0);
        dfs(row + 1 , col , grid , visited , path , row0 , col0);

        dfs(row , col + 1 , grid, visited, path , row0 , col0);
        return;

    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int totalRow = grid.size();
        int totalCol = grid.back().size();
        int count = 0;
        vector<vector<bool>>visited(totalRow , vector<bool>(totalCol , false));
        set<vector<pair<int,int>>>st;
        for(int row = 0 ; row < totalRow ; row++) {
            for(int col = 0 ; col < totalCol ; col++) {
                if(grid[row][col] == 1 && !visited[row][col]) {
                    vector<pair<int,int>>path;
                    dfs(row , col , grid , visited , path , row , col);
                    st.insert(path);
                }
            }
        }
        return st.size();
    }
};
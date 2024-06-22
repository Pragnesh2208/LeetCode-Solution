/**********************************************Optimal approach to Path with Maximum Gold***********************************/ 
/**********************************************Time Complexity  = O (N*M + 3^G)*************************************************/
/**********************************************Here G is total cells conntains Gold and every cells has 3 Direction to explore*********/
/**********************************************Space Complexity  = O ( K )**************************************************/
class Solution {
    int getGold(int row , int col , vector<vector<int>>&grid) {
        int totalRow = grid.size();
        int totalCol = grid.back().size();
        if(row < 0 || row >= totalRow || col < 0 || col >= totalCol || grid[row][col] == 0) return 0;
        int gridValue = grid[row][col];
        grid[row][col] = 0;

        vector<pair<int,int>>directions = {{0 , -1} ,{ 0 , 1 },{ -1 , 0} ,{ 1 , 0}};
        int maxDirection = 0;
        for(int i = 0 ; i < directions.size() ; i++) {
            maxDirection = max(maxDirection , getGold(row + directions[i].first , col + directions[i].second  , grid));
        }
        grid[row][col] = gridValue;
        return maxDirection + grid[row][col];
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int totalRow = grid.size();
        int totalCol = grid.back().size();

        int ans = 0;
        for(int i = 0 ; i < totalRow ; i++) {
            for(int j = 0; j < totalCol ; j++) {
               ans = max(ans , getGold(i , j  , grid ));
            }
        }

        return ans;
    }
};
/**********************************************Optimal approach to Path with Maximum Gold***********************************/ 
/**********************************************Time Complexity  = O (4 ^ K)*************************************************/
/**********************************************Here K is total cells conntains Gold and every cells has 4 Direction*********/
/**********************************************Space Complexity  = O ( K )**************************************************/
class CombinationIterator {
class Solution {
    private:
    void getPath(int row , int col , vector<vector<int>>&grid , int sum , int & ans) {

         ans = max(sum , ans);

        if( row < 0 || row == grid.size() || col < 0  || col == grid[row].size() || grid[row][col] == 0)
            return;
       
        int right[] = {0 , 1 , 0 , -1};
        int left[] = {-1 , 0 , 1 , 0};
        for(int i = 0 ; i < 4 ; i++) {
            sum += grid[row] [col];
            int temp = grid[row][col];
            grid[row][col] = 0;
            getPath(row + left[i] , col + right[i] , grid , sum   , ans );
            grid[row][col] = temp;
            sum -= grid[row][col];
        }
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0 , sum = 0;
        for(int i = 0 ; i < grid.size() ; i++ ) {
            for(int j = 0 ; j < grid[i].size() ; j++ ) {
                if(grid[i][j] != 0) 
                    getPath(i , j , grid , sum  , ans);
            }
        }
        return ans;
    }
};
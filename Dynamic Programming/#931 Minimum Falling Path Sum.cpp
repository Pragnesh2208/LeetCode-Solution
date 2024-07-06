/****************Optimal of Unique Paths using Memoization***********/
/****************Time Complexity = O(N^2)****************************/
/****************Space Complexity = O(N^2)***************************/
class Solution {
    int getMinFallingPath(int row , int col , vector<vector<int>>&matrix, vector<vector<int>>&dp) {
        int totalRow = matrix.size();
        int totalCol = matrix.back().size();
        if(row == totalRow || col == totalCol) return INT_MAX;
        int prevColSum = col - 1 >= 0 ? getMinFallingPath(row + 1 , col - 1 , matrix , dp) : INT_MAX;
        int currColSum = getMinFallingPath(row + 1 , col , matrix, dp);
        int nextColSum = col + 1 < totalCol ? getMinFallingPath(row + 1 , col + 1 , matrix, dp) : INT_MAX;
        int minColSum = min(prevColSum , min(currColSum , nextColSum));
        return dp[row][col] = (minColSum == INT_MAX ? 0 : minColSum) + matrix[row][col] ;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int totalRow = matrix.size();
        int totalCol = matrix.back().size();
        int ans = INT_MAX;
        vector<vector<int>>dp(totalRow + 1 , vector<int>(totalCol , -1));

        for(int col = 0 ; col < totalCol ; col++) {
            ans = min(ans , getMinFallingPath(0 , col , matrix , dp));
        }

        return ans;
    }
};

/****************Optimal of Unique Paths using tabulation***********/
/****************Time Complexity = O(N^2)***************************/
/****************Space Complexity = O(N^2)**************************/
class Solution {    
    int tabulation(vector<vector<int>>&matrix) {
        int totalRow = matrix.size();
        int totalCol = matrix.back().size();
        int ans = INT_MAX;
        vector<vector<int>>dp(totalRow  + 1, vector<int>(totalCol , 0));

        for(int row = totalRow - 1 ; row >= 0 ; row--) {
            for(int col = 0 ; col < totalCol ; col++) {
                int prevColSum = col - 1 >= 0 ? dp[row + 1][col - 1] : INT_MAX;
                int currColSum = dp[row + 1][col];
                int nextColSum = col + 1 < totalCol ? dp[row + 1][col + 1] : INT_MAX;
                int minColSum = min(prevColSum , min(currColSum , nextColSum));
                dp[row][col] = (minColSum == INT_MAX ? 0 : minColSum) + matrix[row][col] ;
                if(row == 0) {
                    ans = min(ans , dp[row][col]);
                }
            }
        }

        return ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        return tabulation(matrix);
    }
};

/****************Optimal of Unique Paths using tabulation***********/
/****************Time Complexity = O(N^2)***************************/
/****************Space Complexity = O(N)**************************/
class Solution {    
    int spaceOptimized(vector<vector<int>>&matrix) {
        int totalRow = matrix.size();
        int totalCol = matrix.back().size();
        int ans = INT_MAX;
        vector<vector<int>>dp(totalRow , vector<int>(totalCol , 0));
        vector<int>nextRow(totalCol , INT_MAX );

        for(int row = totalRow - 1 ; row >= 0 ; row--) {
            vector<int>currRow(totalCol , 0);
            for(int col = 0 ; col < totalCol ; col++) {
                int prevColSum = col - 1 >= 0 ? nextRow[col - 1] : INT_MAX;
                int currColSum = nextRow[col];
                int nextColSum = col + 1 < totalCol ? nextRow[col + 1] : INT_MAX;
                int minColSum = min(prevColSum , min(currColSum , nextColSum));
                currRow[col] = (minColSum == INT_MAX ? 0 : minColSum) + matrix[row][col] ;
                if(row == 0) {
                    ans = min(ans , currRow[col]);
                }
            }
            nextRow = currRow;
        }

        return ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        return spaceOptimized(matrix);  
    }
};
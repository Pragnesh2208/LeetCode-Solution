/****************Solution of Minimum path sum Using backtracking*********************/
/****************Time Complexity = O(  2^ (M * N) )********************************/
/****************Space Complexity = O(M*N)************************************/

#include <bits/stdc++.h> 
using namespace std;
int backtracking(int row , int col , vector<vector<int>>&grid) {
    if(row < 0 || col < 0) return INT_MAX;
    if(row == 0 && col == 0) return grid[row][col];
    return grid[row][col] + min(backtracking(row - 1 , col , grid) , backtracking(row , col - 1 , grid));

}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size() -1;
    int m = grid[0].size() - 1;
    return backtracking(n  , m , grid);
}


/****************Solution of Minimum path sum Using Memoization****************/
/****************Time Complexity = O(  M * N )********************************/
/****************Space Complexity = O(M*N)************************************/

#include <bits/stdc++.h> 
using namespace std;
int memoization(int row , int col , vector<vector<int>>&grid , vector<vector<int>>&dp ) {
    if(row < 0 || col < 0)
        return INT_MAX;
    else if(row == 0 && col == 0)
        return dp[row][col] = grid[row][col];
    if(dp[row][col] != -1) 
        return dp[row][col];
    return dp[row][col]= grid[row][col] + min(memoization(row - 1 , col , grid, dp) , memoization(row , col - 1 , grid , dp));

}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size() -1;
    int m = grid[0].size() - 1;
    vector<vector<int>>dp(n + 1 , vector<int>(m + 1 , -1)); 
    return memoization(n  , m , grid , dp);
}

/****************Solution of Minimum path sum Using Tabulation****************/
/****************Time Complexity = O(  M * N )********************************/
/****************Space Complexity = O(M*N)************************************/

#include <bits/stdc++.h> 
using namespace std;
int tabulation(int row , int col , vector<vector<int>>&grid , vector<vector<int>>&dp ) {
   dp[0][0] = 0;
   for(int i = 0 ; i <= row ; i++) {
       for(int j = 0 ; j <= col ;j++) {
           if(i > 0) 
            dp[i][j] =  dp[i-1][j];
            if(j > 0 )
            dp[i][j] = min(dp[i][j] , dp[i][j-1]);
            dp[i][j] += grid[i][j];

       }
   }
   return dp[row][col];
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size() -1;
    int m = grid[0].size() - 1;
    vector<vector<int>>dp(n + 1 , vector<int>(m + 1 , INT_MAX)); 
    return tabulation(n  , m , grid , dp);
}


/****************Solution of Minimum path sum Using Space Optimization****************/
/****************Time Complexity = O(  M * N )********************************/
/****************Space Complexity = O(1)************************************/
#include <bits/stdc++.h> 
using namespace std;
int spaceOptimization(vector<vector<int>>&grid) {
    int row = grid.size();
    int col = grid[0].size();
  vector<int>prevRow(col , 0);
  for(int i = 0 ; i <row ;i++) {
      vector<int>curRow(col, 0);
      for(int j = 0 ; j < col ; j++) {
         if(i > 0 && j > 0) {
             curRow[j] = min(prevRow[j] , curRow[j-1]);
         }
         else if(i > 0 ) curRow[j] = prevRow[j];
         else curRow[j] = curRow[j-1];
         curRow[j] += grid[i][j];
      }
      prevRow = curRow;
  }
return prevRow[col-1];
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here. 
    return spaceOptimization(grid);
}
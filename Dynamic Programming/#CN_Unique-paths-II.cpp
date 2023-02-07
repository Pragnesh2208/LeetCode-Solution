/****************Solution of Unique Paths II Using backtracking*********************/
/****************Time Complexity = O(  2^ (M * N) )********************************/
/****************Space Complexity = O(M*N)************************************/

#include<bits/stdc++.h>
using namespace std;

int backtracking(int row, int col, vector<vector<int>> &mat ) {
    if(row < 0 || col < 0 || mat[row][col] == -1 ) {
        return 0;
    }

    if(row == 0 && col == 0 ) {
      return 1;
    }

    int left = (backtracking(row - 1,  col  , mat ) )% 1000000007 ;
    int right =  (backtracking(row ,  col - 1 , mat)) % 1000000007;
    return dp[row][col] = (left + right ) % 1000000007;
   
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    return backtracking(n - 1 , m - 1, mat );
}

/****************Solution of Unique Paths II Using Memoization****************/
/****************Time Complexity = O(  M * N )********************************/
/****************Space Complexity = O(M*N)************************************/

#include<bits/stdc++.h>
using namespace std;

int backtracking(int row, int col, vector<vector<int>> &mat , vector<vector<int>> &dp) {
    if(row < 0 || col < 0 || mat[row][col] == -1 ) {
        return 0;
    }

    if(row == 0 && col == 0 ) {
      return dp[row][col] =  1;
    }

    if(dp[row][col] != -1) return dp[row][col];

    int left = (backtracking(row - 1,  col  , mat , dp) )% 1000000007 ;
    int right =  (backtracking(row ,  col - 1 , mat , dp)) % 1000000007;
    return dp[row][col] = (left + right ) % 1000000007;
   
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>>dp(n , vector<int>(m , -1));
    return backtracking(n - 1 , m - 1, mat , dp);
}

/****************Solution of Unique Paths II Using Tabulation*****************/
/****************Time Complexity = O(  M * N )********************************/
/****************Space Complexity = O(M*N)************************************/
#include<bits/stdc++.h>
using namespace std;

int tabulation(int row, int col, vector<vector<int>> &mat , vector<vector<int>> &dp) {
  dp[0][0] = 1;
   for(int i = 0 ; i <= row ; i++ ) {
       for(int j = 0 ; j <= col ; j++) {
           if(i > 0 && mat[i][j] != -1) {
               dp[i][j] += (dp[i-1][j] ) % 1000000007;
           }
           if(j > 0 && mat[i][j] != -1) {
               dp[i][j] += (dp[i][j-1] ) % 1000000007;
           }
       }
   }
   return dp[row][col] % 1000000007;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>>dp(n , vector<int>(m , 0));
    return tabulation(n - 1 , m - 1, mat , dp);
}

/****************Solution of Unique Paths II Using SpaceOptimization*****************/
/****************Time Complexity = O(M * N)********************************/
/****************Space Complexity = O(1)************************************/
#include<bits/stdc++.h>
using namespace std;

int spaceOptimization(int row, int col, vector<vector<int>> &mat) {
       vector<int>prevRow(col + 1 , 0);
        for(int i = 0 ; i <= row ; i++ ) {
       vector<int>currRow(col + 1 , 0);
       
       for(int j = 0 ; j <= col ; j++) {
           if(i == 0 && j == 0) currRow[j] = 1;
           if(mat[i][j] == -1) currRow[j]=0;
           else {
               currRow[j] += ( prevRow[j] ) % 1000000007;
                if(j > 0 ) 
               currRow[j] += (currRow[j-1] ) % 1000000007;   
            }
       }
       prevRow = currRow;
   }
   return prevRow[col] % 1000000007;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    return spaceOptimization(n - 1 , m - 1, mat );
}
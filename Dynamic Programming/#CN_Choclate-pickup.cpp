//Reference Video : https://www.youtube.com/watch?v=QGfn7JeXK54
//space Optimization is in todo in revision part

/****************Solution of Choclate Pickup using backtracking**************/
/****************Time Complexity = O( M^3 * N^3)*****************************/
/****************Space Complexity = O( M )***********************************/
/*****************Here M is stands for Row , and N for Column****************/

#include <bits/stdc++.h> 
using namespace std;
int helper(int row , int col1 , int col2 , int totalRow , int totalCol ,vector<vector<int>> &grid ) {
    if(row >= totalRow || col1 < 0 || col2 < 0 || col1 >= totalCol || col2 >= totalCol) {
        return INT_MIN;
    }

    int val = 0;
    for(int i = -1 ; i  <= 1 ; i++) {
        for(int j = -1 ; j <= 1 ; j++) {
            int temp =  helper(row + 1 , col1 + i , col2 + j , totalRow , totalCol , grid );
            if(temp != INT_MIN) {
                if(col1 == col2) val = max(val , temp + grid[row][col1]);
                else
                val = max(val , temp + grid[row][col1] + grid[row][col2]);
            }else {
                 if(col1 == col2) val = max(val ,  grid[row][col1]);
                else
                val = max(val , grid[row][col1] + grid[row][col2]);
            }
        }
    }
    return  val;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>> dp(r , vector<vector<int>>(c , vector<int>(c,-1)));
    return helper(0 , 0 , c-1 , r , c , grid );
}

/****************Solution of Choclate Pickup using Memoization**************/
/****************Time Complexity = O(M*N)*****************************/
/****************Space Complexity = O( M * N * N )***********************************/
/*****************Here M is stands for Row , and N for Column****************/


#include <bits/stdc++.h> 

int helper(int row , int col1 , int col2 , int totalRow , int totalCol ,vector<vector<int>> &grid , vector<vector<vector<int>>>&dp) {
    if(row >= totalRow || col1 < 0 || col2 < 0 || col1 >= totalCol || col2 >= totalCol) {
        return INT_MIN;
    }
    if(dp[row][col1][col2] != -1) return dp[row][col1][col2];

    int val = 0;
    for(int i = -1 ; i  <= 1 ; i++) {
        for(int j = -1 ; j <= 1 ; j++) {
            int temp =  helper(row + 1 , col1 + i , col2 + j , totalRow , totalCol , grid , dp);
            if(temp != INT_MIN) {
                if(col1 == col2) val = max(val , temp + grid[row][col1]);
                else
                val = max(val , temp + grid[row][col1] + grid[row][col2]);
            }else {
                 if(col1 == col2) val = max(val ,  grid[row][col1]);
                else
                val = max(val , grid[row][col1] + grid[row][col2]);
            }
        }
    }
    return dp[row][col1][col2] = val;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>> dp(r , vector<vector<int>>(c , vector<int>(c,-1)));
    return helper(0 , 0 , c-1 , r , c , grid , dp);
}


/****************Solution of Choclate Pickup using Tabulation**************/
/****************Time Complexity = O(M * N)*****************************/
/****************Space Complexity = O( M * N * N )***********************************/
/*****************Here M is stands for Row , and N for Column****************/

#include <bits/stdc++.h> 

int helper(int row , int col1 , int col2 , int totalRow , int totalCol ,vector<vector<int>> &grid , vector<vector<vector<int>>>&dp) {
   
   for(int i = 0 ; i < totalCol ; i++) {
       for(int j = 0 ; j < totalCol ;j++) {
            if(i == j )dp[row][i][j] = grid[row][i];
            else dp[row][i][j] = grid[row][i] + grid[row][j];
       }
   }


   for(int i = totalRow - 2 ; i >= 0;i--) {
       for(int j = 0 ; j < totalCol ; j++) {
           for(int k = 0 ; k < totalCol ; k++) {
                    for(int di = -1 ; di  <= 1 ; di++) {
                        for(int dj = -1 ; dj <= 1 ; dj++) {
                            int val = 0;
                            if(j + di >= 0 && j + di < totalCol && k + dj >= 0 && k + dj < totalCol ) { 
                                int temp =  dp[i + 1 ] [j + di]  [k + dj];
                                if(j == k) val =  temp + grid[i][j + di];
                                else
                                val = temp + grid[i][j] + grid[i][k];
                                 dp[i][j][k] = max(val , dp[i][j][k]);
                            }   
                        }
                    }
            }
        }
   }

    return dp[0][col1][col2] ;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>> dp(r , vector<vector<int>>(c , vector<int>(c,0)));
    return helper(r - 1 , 0 , c-1 , r , c , grid , dp);
}
/****************Solution of Unique Paths using Backtracking*********************/
/****************Time Complexity = O(2 ^ ( M * N) )********************************/
/****************Space Complexity = O( M * N )************************************/
#include <bits/stdc++.h> 
using namespace std;
int backtracking(int row , int col  ){
	if(row < 0 || col < 0) return 0;
	else if(row == 0 && col == 0) return 1;

	return  backtracking(row - 1 , col ) + backtracking(row , col -1 );
} 

int uniquePaths(int m, int n) {
	return backtracking(m-1 , n-1 );
}

/****************Solution of Unique Paths using Memoization*********************/
/****************Time Complexity = O( M * N)********************************/
/****************Space Complexity = O( M * N )************************************/

#include <bits/stdc++.h> 
using namespace std;
int backtracking(int row , int col , vector<vector<int>>&dp ){
	if(row < 0 || col < 0) return 0;
	else if(row == 0 && col == 0) return 1;
	if(dp[row][col] != -1) return dp[row][col];
	return dp[row][col] = backtracking(row - 1 , col , dp) + backtracking(row , col -1  , dp);
} 

int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m , vector<int>(n , -1));
	return backtracking(m-1 , n-1 , dp);
}

/****************Solution of Unique Paths using Tabulation*********************/
/****************Time Complexity = O( M * N)********************************/
/****************Space Complexity = O( M * N )************************************/

#include <bits/stdc++.h> 
using namespace std;
int tabulation(int row , int col , vector<vector<int>>&dp ){
	dp[0][0] = 1;
	for(int i = 0 ; i <= row; i++) {
		for(int j = 0 ; j <= col ;j++) {
			if(i >= 1) 
			dp[i][j] += dp[i-1][j];
			if(j >=1)
			dp[i][j] += dp[i][j-1];
		}
	}
	return dp[row][col];
} 

int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m , vector<int>(n , 0));
	return tabulation(m-1 , n-1 , dp);
}

/****************Solution of Unique Paths using spaceOptimization*********************/
/****************Time Complexity = O( M * N)********************************/
/****************Space Complexity = O(1)************************************/

#include <bits/stdc++.h> 
using namespace std;
int spaceOptimization(int row , int col  ){
	vector<int>prevRow(col + 1 ,1);
	for(int i = 1 ; i <= row; i++) {
		vector<int>curRow(col + 1 , 0);
		for(int j = 0 ; j <= col ;j++) {
			if( j >= 1 ) {
				curRow[j] += curRow[j-1];
			}

			curRow[j] += prevRow[j];
		}
		prevRow = curRow;
	}
	return prevRow[col];
} 

int uniquePaths(int m, int n) {
	// Write your code here.
	return spaceOptimization(m-1 , n-1);
}
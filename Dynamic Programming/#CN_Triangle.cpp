/****************Solution of Triangle using Memoization*********************/
/****************Time Complexity = O( M * N)********************************/
/****************Space Complexity = O( M * N )************************************/
#include <bits/stdc++.h> 
using namespace std;
int memoization(int row , int col ,vector<vector<int>>&triangle , vector<vector<int>>&dp) {
	if(row == 0 && col == 0 ) {
		return dp[row][col] = triangle[row][col];
	}
	if(row < 0 || col < 0 || col > row )return INT_MAX;
	if (dp[row][col] != INT_MIN) return dp[row][col];
	int prevRow = memoization(row -1 , col - 1, triangle,dp);
	int diagRow = memoization(row -1 , col , triangle,dp);

	if(prevRow == INT_MAX) return dp[row][col] = triangle[row][col] + diagRow;
	else if( diagRow == INT_MAX) return dp[row][col] = triangle[row][col] + prevRow;
	else return dp[row][col] = min(triangle[row][col] + prevRow , triangle[row][col] + diagRow);
	
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>>dp(n ,vector<int>(n,INT_MIN));
	int ans = INT_MAX;
	for(int i = 0 ; i < n ;i++) {
		int temp = memoization(n-1  , i, triangle , dp);
		ans = min(ans , temp);
	}
	return ans;
}

/****************Solution of Triangle Using Tabulation*********************/
/****************Time Complexity = O( M * N)********************************/
/****************Space Complexity = O( M * N )************************************/

#include <bits/stdc++.h> 
using namespace std;
int tabulation(int row ,vector<vector<int>>&triangle , vector<vector<int>>&dp) {

	for(int i = 1 ; i <= row ; i++) {
		for(int j = 0 ; j <= i ; j++) {
			if(j != i)
			dp[i][j] = min(dp[i][j] , triangle[i][j] + dp[i-1][j] );
			if(j > 0)
			dp[i][j] = min(dp[i][j] , triangle[i][j] + dp[i-1][j-1]);
		}

	}

	int ans = INT_MAX;

	for(int i = 0 ; i <= row ;i++) {
		ans = min(ans , dp[row][i]);
	}

	return ans;
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>>dp(n ,vector<int>(n,INT_MAX));
	dp[0][0] = triangle[0][0];

	return tabulation(n-1 , triangle , dp);;
}

/****************Solution of Triangle using space optimization*********************/
/****************Time Complexity = O( M * N)********************************/
/****************Space Complexity = O(1)************************************/

#include <bits/stdc++.h> 
using namespace std;
int spaceOptimization(int row ,vector<vector<int>>&triangle) {
	vector<int>prevRow(row + 1 , INT_MAX);
	prevRow[0] = triangle[0][0];
	for(int i = 1 ; i <= row ; i++) {
		vector<int>curRow(row  + 1, INT_MAX);
		for(int j = 0 ; j <= i ; j++) {
			if(j != i)
			curRow[j] = triangle[i][j] + prevRow[j] ;
			if(j > 0)
			curRow[j] = min(curRow[j] , triangle[i][j] + prevRow[j-1]);
		}
		prevRow = curRow;
	}

	int ans = INT_MAX;

	for(int i = 0 ; i <= row ;i++) {
		ans = min(ans , prevRow[i]);
	}

	return ans;
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	return spaceOptimization(n-1 , triangle );
}
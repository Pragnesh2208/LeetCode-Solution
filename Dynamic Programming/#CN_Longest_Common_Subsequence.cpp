/****************Find Longest Common Subsequence using memoization*******************/
/****************Time Complexity = O(M * N)*************************************/
/****************Space Complexity = O(N * M)************************************/
#include<vector>
int memoization(int ind1 , int ind2 , string &s , string &t , vector<vector<int>>&dp) {
	if(ind1 < 0 || ind2 < 0) return 0;
	if(dp[ind1][ind2] !=  -1 ) return dp[ind1][ind2] ;
	if(s[ind1] == t[ind2]) return dp[ind1][ind2] =  (1 + memoization(ind1 - 1 , ind2 - 1 , s , t , dp));
	return dp[ind1][ind2]  = max(memoization(ind1 - 1 , ind2 , s , t , dp) , memoization(ind1 , ind2 - 1 , s , t , dp));
}

/****************Find Longest Common Subsequence using tabulation*******************/
/****************Time Complexity = O(M * N)*************************************/
/****************Space Complexity = O(N * M)************************************/

int tabulation(string &s , string &t){
	int n = s.length();
	int m = t.length();
	vector<vector<int>>dp( n , vector<int>(m , -1));
	for(int i = 0 ; i < m ;i++) 
		if(s[0] == t[i]) dp[0][i] = 1;
	for(int i = 1 ; i < n ; i++) {
		for(int j = 0 ; j < m ; j++) {
			if(s[i] == t[j]) dp[i][j] = 1 + dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		}
	}
	return dp[n -1][m-1];
}

/****************Find Longest Common Subsequence using spaceOptimization*******************/
/****************Time Complexity = O(M * N)*************************************/
/****************Space Complexity = O(N)************************************/
int spaceOptimized(strin &s ,string &t) {
	int n = s.length();
	int m = t.length();
	vector<int>prev( n , -1);

	for(int i = 0 ; i < m ;i++) 
		if(s[0] == t[i]) prev[i]++;

	for(int i = 1 ; i < n ; i++) {
			vector<int>cur( n , -1);
		for(int j = 0 ; j < m ; j++) {
			if(s[i] == t[j]) cur[j] = 1 + dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		}
		prev = cur;
	}
	return prev[m-1];
}

int lcs(string s, string t)
{
	//Write your code here
	int n  = s.length() - 1;
	int m =  t.length() -1;
	vector<vector<int>>dp( n + 1  , vector<int>(m +1  , -1));
	return tabulation(s , t);
	return memoization( n , m , s , t , dp);
}
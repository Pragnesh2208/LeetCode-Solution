/*
Greedy Dont Work for below cases
weight =[3 , 3  , 5];
value = [9 , 9 , 15];
MaxWeight = 6;
*/
#include <bits/stdc++.h> 
using namespace std;
/****************Solution of 0/1 KnapSack using Memoization**********/
/****************Time Complexity = O(N * MaxWeight)********************************************/
/****************Space Complexity = O(N * MaxWeight)************************************************/
int memoization(int ind , int maxWeight , vector<int>&weight , vector<int>&value  , vector<vector<int>>&dp) {
	if(ind == 0 ){
		if(weight[ind] <= maxWeight) return dp[ind][weight[ind]] =  value[ind];
		else return dp[ind][maxWeight] = 0;
	}
	if(dp[ind][maxWeight] != -1) return dp[ind][maxWeight];
	int pick = 0 , nonPick = 0;
	if(weight[ind] <= maxWeight) pick = value[ind] +memoization(ind - 1 , maxWeight - weight[ind] , weight , value , dp);
	nonPick = memoization(ind - 1, maxWeight , weight , value , dp);
	return dp[ind][maxWeight] = max(pick , nonPick);
}

/****************Solution of 0/1 KnapSack using Tabulation**********/
/****************Time Complexity = O(N * MaxWeight)********************************************/
/****************Space Complexity = O(N * MaxWeight)************************************************/
int tabulation(int &n , int &maxWeight , vector<int>&weight , vector<int>&value) {
	vector<vector<int>>dp(n , vector<int>(maxWeight + 1 , 0));
	if(weight[0] <= maxWeight)
		dp[0][weight[0]] = value[0];

	// for(int i = 1; i < n ;i++) {
	// 	dp[i][0] = weight[i] == 0 ? dp[i-1][0] + value[i] : dp[i-1][0];
	// }

	for(int i = 1 ; i < n ; i++) {
		for(int j = 0; j <= maxWeight ; j++) {
			int pick = 0 , nonPick = 0;
			if(weight[i] <= j) {
				pick = value[i] + dp[i-1][j-weight[i]];
			}
			nonPick = dp[i-1][j];
			dp[i][j] = max(pick , nonPick);
		}
	}
	int ans = 0;
	for(int i = maxWeight ; i >= 0 ;i--){
		ans = max(ans , dp[n-1][i]);
	}
	return ans;
} 


/****************Solution of 0/1 KnapSack using Memoization**********/
/****************Time Complexity = O(N * MaxWeight)********************************************/
/****************Space Complexity = O(MaxWeight)************************************************/
int optimized(int n , int maxWeight , vector<int> weight, vector<int> value) {
	vector<int>prev(maxWeight + 1 , 0);
	if(maxWeight >= weight[0])
	prev[weight[0]] = value[0];
	for(int i = 1 ; i < n ; i++) {
		vector<int>cur(maxWeight + 1 , 0);
		for(int j = 0 ; j <= maxWeight ; j++) {
			int pick = 0 , nonPick = 0;
			if(weight[i] <= j) pick = value[i] + prev[j - weight[i]];
			nonPick = prev[j];
			cur[j] = max(pick , nonPick);
		}
		prev = cur;
	}
	int ans = 0;

	for(int i = maxWeight ; i >= 0 ;i--){
		ans = max(ans , prev[i]);
	}
	return ans;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>>dp(n , vector<int>(maxWeight + 1 , -1));
	return optimized(n , maxWeight , weight , value);
	return tabulation(n , maxWeight , weight , value);
	return memoization(n-1, maxWeight , weight , value , dp);
	
	
}
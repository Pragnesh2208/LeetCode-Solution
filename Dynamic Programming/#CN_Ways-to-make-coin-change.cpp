#include <bits/stdc++.h>
using namespace std;
/****************Solution of Ways to make coin change using Memoization**********/
/****************Time Complexity = O(M * Target)********************************************/
/****************Space Complexity = O(M * Target)************************************************/
long memoization(int ind , vector<int>&arr , int target , vector<vector<long>>&dp) {

    if(ind == 0) {
        if(target % arr[ind] == 0) return dp[ind][target] =  1;
        else return dp[ind][target] = 0; 
    }
  
    if(dp[ind][target] != -1) return dp[ind][target];
    
    long pick = 0 , nonPick = 0;
    if(target >=  arr[ind]) {
        pick = memoization(ind , arr  , target - arr[ind] , dp);
    }
    nonPick = memoization(ind - 1  , arr , target , dp);
    return dp[ind][target] = (pick + nonPick);
}

/****************Solution of Ways to make coin change using Tabulation**********/
/****************Time Complexity = O(M * Target)********************************************/
/****************Space Complexity = O(M * Target)************************************************/

long tabulation(int &n , int * arr , int &target) {
    vector<vector<long>>dp(n , vector<long>(target + 1 , 0));
    for(long i = 0 ; i <= target ; i++) {
        dp[0][i] =  (i % *arr == 0) ? 1 : 0;
    }
    
    for(int i = 1 ; i < n ; i++) {
        arr++;
        dp[i][0] = dp[i-1][0];

        for(long j = 1 ; j <= target ; j++) {
            long pick = 0 , nonPick = 0;
            if(j >=  *arr) {
                pick = dp[i][j - *arr];
            }
            nonPick = dp[i - 1][j];
            dp[i][j] = pick + nonPick;
        }
    }
    return dp[n-1][target];
}

/****************Solution of Ways to make coin change using Space Optimization**********/
/****************Time Complexity = O(M * Target)********************************************/
/****************Space Complexity = O(Target)************************************************/

long optimization(int & n , vector<int>&arr , int &target) {
    vector<long>prev(target + 1 , 0);
    for(int i = 0 ; i <= target ; i++) prev[i] = (i % arr[0]) == 0 ? 1 : 0;
    for(int i = 1; i < n;i++) {
        vector<long>cur(target + 1, 0);
        cur[0] = prev[0];
        for (int j = 1; j <= target; j++) {
            long pick = 0 , nonPick = 0;
            if(j >= arr[i]) pick = cur[j-arr[i]];
            nonPick = prev[j];
            cur[j] = pick + nonPick;
        }
        prev = cur;
    }
    return prev[target];
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<int>arr(n ,0);
    for(int i = 0 ; i < n ;i++) arr[i] = *denominations++;
    vector<vector<long>> dp(n , vector<long>(value + 1 , -1));
    return optimization(n , arr , value);
    return tabulation(n , denominations , value);
    return memoization(n-1 , arr , value , dp);
}
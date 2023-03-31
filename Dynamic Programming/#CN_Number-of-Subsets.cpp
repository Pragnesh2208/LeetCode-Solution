/*
Edge Cases are
arr=[0,0,1] , target = 1;
arr = [2,3,1] , target = 3;
*/
#include <bits/stdc++.h>
/****************Solution of Minimum path sum Using Memoization****************/
/****************Time Complexity = O(N * Target)********************************/
/****************Space Complexity = O(N * Target)************************************/
int memoization(int ind , vector<int>&num , int tar , vector<vector<int>>&dp) {
   
    if(ind < 0 )return tar == 0 ? 1 : 0;
    int pick = 0 , nonPick = 0;
    if(dp[ind][tar] != -1) return dp[ind][tar];
    if(num[ind]<= tar) {
        pick = helper(ind - 1 , num , tar - num[ind] , dp);
    } 
    nonPick = helper(ind - 1 , num , tar , dp);
    return dp[ind][tar] = pick + nonPick;
} 

/****************Solution of Minimum path sum Using Tabulation****************/
/****************Time Complexity = O(N * Target)********************************/
/****************Space Complexity = O(N * Target)************************************/
int tabulation(int ind , vector<int>&num , int tar){
    int n = num.size();
    vector<vector<int>>dp(n , vector<int>(tar + 1 , 0));
    dp[0][0] = 1; 
    if(num[0] <= tar)
    dp[0][num[0]]++;

    for(int i = 1 ; i < n ; i++) {
        dp[i][0] = num[i] == 0 ? 2 * dp[i-1][0] : dp[i-1][0];
    }

    for(int i = 1 ; i < n ; i++) {
        for(int j = 1 ; j <= tar ; j++) {
            int pick = 0, nonPick = 0;
            if(num[i]<= j) {
                pick = dp[i- 1][j - num[i]];
            } 
            nonPick = dp[i - 1][j];
            dp[i][j] = pick + nonPick;
        }
    }
    return dp[ind][tar];
}

/****************Solution of Minimum path sum Using Memoization****************/
/****************Time Complexity = O(N * Target)********************************/
/****************Space Complexity = O(Target)************************************/
int optimize(int ind , vector<int>&num , int tar) {
    int n = num.size();
    vector<int>prev(tar+ 1 , 0);
    prev[0] = 1; 
    if(num[0] <= tar)
    prev[num[0]]++;

    for(int i = 1 ; i < n ; i++) {
        vector<int>curr(tar + 1 , 0);

        curr[0] = num[i] == 0 ? 2 * prev[0] : prev[0];
        for(int j = 1 ; j <= tar ; j++) {
            int pick = 0, nonPick = 0;
            if(num[i]<= j) {
                pick = prev[j - num[i]];
            } 
            nonPick = prev[j];
            curr[j] = pick + nonPick;
        }
        prev = curr;
    }
    return prev[tar];
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>>dp(n , vector<int>(tar + 1 , -1));
    return optimize(n - 1 , num , tar);
    return tabulation(n - 1 , num , tar);
    return memoization(n - 1 , num , tar , dp);
}
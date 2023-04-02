#include <bits/stdc++.h> 
using namespace std;
/****************Solution of Partition With Given Difference using Memoization**********/
/****************Time Complexity = O(M * Target)********************************************/
/****************Space Complexity = O(M * Target)************************************************/
int memoization(int ind , int &diff , int s2 , vector<int>&arr , vector<vector<int>>&dp) {
    if(ind < 0 ) {
        if(s2 == 0) return 1;
        else return 0; 
    }

    if(dp[ind][s2] != -1) return dp[ind][s2];
    int pick = 0 , nonPick = 0;
    if(arr[ind] <= s2)

    pick = helper(ind - 1, diff , s2 - arr[ind], arr , dp);
    nonPick = helper(ind - 1, diff ,s2 , arr , dp);

    return dp[ind][s2] = (pick + nonPick) % int(1e9+7);
}

/****************Solution of Partition With Given Difference using Tabulation**********/
/****************Time Complexity = O(M * Target)***************************************/
/****************Space Complexity = O(M * Target)**************************************/
int tabulation(int n , int target , vector<int>&arr) {
    vector<vector<int>>dp(n , vector<int>(target + 1, 0));
    dp[0][0] = 1;
    if(arr[0] <= target) dp[0][arr[0]]++;
    for(int i = 1; i < n ; i++) {
        dp[i][0] = arr[i] == 0 ? 2 * dp[i-1][0] : dp[i-1][0];
        for(int j = 1; j <= target ; j++) {
            int pick = 0 , nonPick = 0;
            if(arr[i] <= j) pick = dp[i-1][j - arr[i]];
            nonPick = dp[i-1][j];
            dp[i][j] = (pick + nonPick) % int(1e9+7);
        }
    }
    return dp[n-1][target];
}

/****************Solution of Partition With Given Difference using Space Optimization*******/
/****************Time Complexity = O(M * Target)********************************************/
/****************Space Complexity = O(M * Target)*******************************************/
int optimized (int &n , int &target , vector<int>&arr) {
    vector<int>prev(target + 1 , 0);
    prev[0]= 1;
    if(arr[0] <= target) prev[arr[0]]++;
    for(int i = 1; i < n;i++){
        vector<int>cur(target + 1 , 0);
        cur[0] = arr[i] == 0 ?  2 * prev[0]: prev[0];

        for(int j = 1 ; j <= target ; j++) {
            int pick = 0 , nonPick = 0;
            if(arr[i] <= j) pick = prev[j - arr[i]];
            nonPick = prev[j];
            cur[j] = (pick + nonPick) % int(1e9+7);
        }
        prev = cur;
    }
    return prev[target];
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.

    int totalSum = accumulate(arr.begin() , arr.end() , 0);
    if(totalSum - d < 0 || (totalSum - d) % 2 != 0) return 0;
    int s2 = (totalSum - d) / 2;
  
    vector<vector<int>>dp(n , vector<int>(s2+ 1, -1));
    return optimized(n , s2 , arr);
    return tabulation(n, s2, arr);
    return memoization(n, d , s2 , arr , dp);
}
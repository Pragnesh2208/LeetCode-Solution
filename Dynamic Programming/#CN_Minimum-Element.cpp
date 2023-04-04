#include <bits/stdc++.h> 
using namespace std;
/****************Solution of Minimum Element using Memoization**********/
/****************Time Complexity = O(N * Target)************************/
/****************Space Complexity = O(N * Target)***********************/
int memoization(int ind , vector<int>&num , int target , vector<vector<int>>&dp) {
    if(ind == 0) {
        if(target % num[ind] == 0) return target / num[ind];
        else return INT_MAX;
    }

    if(dp[ind][target] != -1) return dp[ind][target];

    int pick = INT_MAX , nonPick = INT_MAX;

    if(target >= num[ind])
    pick =  memoization(ind , num , target - num[ind] , dp);

    nonPick = memoization(ind - 1 , num , target , dp);
    if(pick != INT_MAX) pick++;
    return dp[ind][target] =  min(pick , nonPick);
}

/****************Solution of Minimum Element using Tabulation**********/
/****************Time Complexity = O(N * Target)************************/
/****************Space Complexity = O(N * Target)***********************/
int tabulation(int &n , vector<int>&num ,int &target) {

    vector<vector<int>>dp(n , vector<int>(target + 1 , INT_MAX));

    for(int i = 0 ; i <= target ; i++) {
      if(i % num[0] == 0 ) dp[0][i] = i / num[0];
    }
   
    for(int i = 1; i < n ; i++) {
        dp[i][0] = num[i] == 0 ? 1 : dp[i-1][0];
        
        for(int j = 1 ; j <= target ; j++) {
            int pick = INT_MAX , nonPick = INT_MAX;

            if(j > num[i]) pick = min(dp[i-1][j - num[i]] , dp[i][j - num[i]]);
            if(pick != INT_MAX) pick++;
            if(j == num[i]) pick = 1;
           
            nonPick = dp[i-1][j];
            dp[i][j] = min(pick , nonPick); 
        }
    }
    
    return dp[n-1][target] == INT_MAX ? -1 : dp[n-1][target] ;
}

/****************Solution of Minimum Element using Space Optimization**********/
/****************Time Complexity = O(N * Target)************************/
/****************Space Complexity = O(Target)***********************/
int optimize(int n , vector<int>&num , int &target) {

    vector<int>prev(target + 1, INT_MAX);

    for(int i = 0 ;i <= target ; i++) {
        if(i % num[0] == 0 ) prev[i] = i / num[0];
    }

    for(int i = 1 ; i < n ; i++) {
        vector<int>cur(target + 1 , INT_MAX);

        for(int j = 0 ; j <= target ; j++) {
            int pick = INT_MAX , nonPick = INT_MAX;
            if(num[i] == j) pick = 1; 
            if(num[i] < j) {
                pick = min(cur[j - num[i]] , prev[j - num[i]]);
                if(pick != INT_MAX) pick++; 
            }

            nonPick = prev[j];
            cur[j] = min(pick , nonPick);
        }
        prev = cur;
    }

    return prev[target] != INT_MAX ? prev[target] : -1; 
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.

    int n = num.size();
    vector<vector<int>> dp(n , vector<int>(x+1,-1));
    if(x == 0) return 0;
    return optimize( n , num , x);
    return tabulation(n, num, x);
    int ans =  memoization(n-1 , num , x , dp);
    return ans == INT_MAX ? -1 : ans ;
}
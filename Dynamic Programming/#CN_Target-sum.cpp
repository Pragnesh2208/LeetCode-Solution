#include <bits/stdc++.h> 
using namespace std;
/****************Solution of Target Sum using Memoization**********/
/****************Time Complexity = O(M * Target)********************************************/
/****************Space Complexity = O(M * Target)************************************************/
int memoization(int ind , vector<int>&arr , int target , vector<vector<int>>&dp) {
    if(ind == 0 ){
        int temp = 0;
        if(target == arr[ind] ) temp = 1;
        if(target == 0) temp++;
        return  dp[ind][target] = temp;
    }
    if(dp[ind][target] != -1) return dp[ind][target];
    int pick = 0 , nonPick = 0;
    if(target >= arr[ind])
        pick =  memoization(ind - 1 , arr , target - arr[ind] , dp);
    nonPick =  memoization(ind - 1  , arr , target , dp);
    return  dp[ind][target] = pick + nonPick;
}
/****************Solution of Target Sum using Tabulation**********/
/****************Time Complexity = O(M * Target)********************************************/
/****************Space Complexity = O(M * Target)************************************************/
int tabulation(int &n , vector<int>&arr , int &target) {
    vector<vector<int>>dp( n , vector<int>(target + 1 , 0));
    dp[0][0]++;
    if(target >= arr[0]) dp[0][arr[0]]++;
    for(int i = 1;  i < n ; i++) {
        dp[i][0] = arr[i] == 0 ? 2 * dp[i-1][0] : dp[i-1][0];
        for(int j = 1 ; j <= target ; j++){
            int pick = 0 , nonPick = 0;
            if(j >= arr[i]) pick = dp[i-1][j - arr[i] ];
            nonPick = dp[i-1][j];
            dp[i][j] = pick + nonPick;
        }

    }
    return dp[n-1][target];
}
/****************Solution of Target Sum using Memoization**********/
/****************Time Complexity = O(M * Target)********************************************/
/****************Space Complexity = O(Target)************************************************/
int optimize(int &n , vector<int>&arr , int &target){
    vector<int>prev(target + 1 );
    prev[0] = 1;
    if(arr[0] <= target) prev[arr[0]]++;
    for(int i = 1 ; i < n ; i++) {
        vector<int>cur(target + 1,0);
        cur[0] = arr[i] == 0 ? 2 * prev[0] : prev[0];
        for(int j = 1; j <= target ; j++) {
             int pick = 0 , nonPick = 0;
            if(j >= arr[i]) pick = prev[j - arr[i]];
            nonPick = prev[j];
            cur[j] = pick + nonPick;
        }
        prev = cur;
    }
    return prev[target];

}
int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    int total = accumulate(arr.begin(), arr.end(), 0);
    if((total - target < 0) || (total - target) % 2 != 0) return 0;
    target = (total - target) / 2;
    vector<vector<int>>dp( n , vector<int>(target + 1 , -1));
    return optimize(n, arr, target);
    return tabulation(n, arr, target);
    return memoization(n - 1 , arr , target , dp);
}

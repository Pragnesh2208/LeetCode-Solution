/*
Solution Using Memoization
Time Complexity = O(N^3)
Space Complexity = O(N^2)
Auxilary Space Complexity = O(N)
Without memoization time complexity would be exponential
*/
#include <bits/stdc++.h> 
int mcm(int i , int j , vector<int>&arr , vector<vector<int>>&dp) {
    if(i == j ) return 0;
    if(dp[i][j] != - 1) return dp[i][j];
    int minStep = INT_MAX;
    for(int k = i ; k < j ; k++) {
        int step = arr[i-1] * arr[k] * arr[j] + mcm(i , k , arr , dp) + mcm(k + 1 , j , arr , dp);
        minStep = min(minStep , step);
    }
    return dp[i][j] = minStep;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>>dp(N , vector<int>( N , -1)); 
    return mcm(1 , N - 1 , arr , dp);
}


/*
Solution Using Tabulation
Time Complexity = O(N^3)
Space Complexity = O(N^2)
Auxilary Space Complexity = O(N)
*/
#include <bits/stdc++.h> 

int tabulation(vector<int>&arr , int N)  {
    vector<vector<int>>dp(N , vector<int>( N , -1)); 
    for(int i = 1 ; i < N; i++) dp[i][i] = 0;
    for(int i = N - 1 ; i >= 0 ; i-- ){
        for(int j = i + 1 ; j < N ; j++) {
            int minStep = INT_MAX;
            for(int k = i ; k < j ; k++) {
                int step = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                minStep = min(minStep , step);
            }
            dp[i][j] = minStep;
        }
    }
    return dp[1][N-1];
}
int matrixMultiplication(vector<int> &arr, int N)
{
    return tabulation(arr , N);
}
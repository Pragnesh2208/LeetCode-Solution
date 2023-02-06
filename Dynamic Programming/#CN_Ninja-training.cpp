/****************Solution of Ninja Training using Backtracking*********************/
/****************Time Complexity = O(2 ^ ( 3 * n) )********************************/
/****************Space Complexity = O(N)************************************/

#include<bits/stdc++.h>
using namespace std;
int backtracking(int ind ,vector<vector<int>> &points , int i ) {
    if(ind == 0) {
        return points[ind][i];
    }
    return  max(points[ind][i] + backtracking(ind - 1 , points , (i + 1) % 3 ) , 
    points[ind][i] + backtracking(ind - 1 , points , (i + 2) % 3 ) );
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return max(backtracking(n -1 , points , 0 ) , max(backtracking(n -1 , points , 1 ) , backtracking(n -1 , points , 2)));
}


/****************Solution of Ninja Training using memoization*******************/
/****************Time Complexity = O(N)*************************************/
/****************Space Complexity = O(N)************************************/

#include<bits/stdc++.h>
using namespace std;
int memoization(int ind ,vector<vector<int>> &points , int i ,vector<vector<int>>&dp ) {
    if(ind == 0) {
        return dp[ind][i] = points[ind][i];
    }
    if(dp[ind][i] != -1) return dp[ind][i];
    return dp[ind][i] =  max(points[ind][i] + memoization(ind - 1 , points , (i + 1) % 3 , dp ) , 
    points[ind][i] + memoization(ind - 1 , points , (i + 2) % 3 , dp ) );
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n , vector<int>(3, -1));
    return max(memoization(n -1 , points , 0 , dp) , max(memoization(n -1 , points , 1 , dp) , memoization(n -1 , points , 2 , dp)));
}

/****************Solution of Ninja Training using tabulation*******************/
/****************Time Complexity = O(N)*************************************/
/****************Space Complexity = O(N)************************************/

#include<bits/stdc++.h>
using namespace std;

int tabulation(vector<vector<int>> &points) {
    int n = points.size();
    vector<vector<int>>dp(  n , vector<int>(3 , -1));

    for(int i = 0 ; i < 3 ;i++){
        dp[0][i] = points[0][i];
    }
    
    for(int i = 1 ; i < n ; i++) {
        for(int j = 0 ;j  < 3 ; j++) {
            dp[i][j] = max( points[i][j] + dp[i-1][ ( j + 2 ) % 3] , points[i][j] + dp[i-1][ ( j + 1 ) % 3]);
        }
    }

    return max(dp[n-1][0] , max(dp[n-1][2] , dp[n-1][1]));
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return tabulation(points);
}


/****************Solution of Ninja Training using spaceOptimization*******************/
/****************Time Complexity = O(N)*************************************/
/****************Space Complexity = O(1)************************************/

#include<bits/stdc++.h>
using namespace std;

int spaceOptimization(vector<vector<int>> &points) {
    vector<int>prev(3 , -1);
    vector<int>prev2(3 , -1);
    int n = points.size();
    for(int i = 0 ; i < 3 ; i++) {
        prev[i] = points[0][i];
    }

    for(int i = 1 ; i < n ; i++) {
        for(int j = 0 ; j < 3 ; j++) {
            prev2[j] = max(points[i][j] + prev[( j + 1)% 3 ] , points[i][j] + prev[(j + 2) % 3]);
        }
        prev = prev2;
    }
    return max(prev[0] , max(prev[1] , prev[2]));
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return spaceOptimization(points);
}
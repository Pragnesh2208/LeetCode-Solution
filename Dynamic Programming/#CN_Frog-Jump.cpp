/****************Solution for Frog jump using Memoization*******************/
/****************Time Complexity = O(N)*************************************/
/****************Space Complexity = O(N)************************************/
int memoization(int i , vector<int>&heights , vector<int>&dp){
    if(i == 0) {
        dp[0] = 0;
        return dp[0];
    }
    if(dp[i] != -1) return dp[i];

    int left = INT_MAX , right = INT_MAX;
     if(i-1 >= 0)
             left = memoization(i-1  , heights , dp) + abs(heights[i]  - heights[i-1]);
        if(i - 2 >= 0)
            right = memoization(i-2  , heights , dp) + abs(heights[i] - heights[i-2]);
    dp[i] = min(left , right);
    return dp[i];
}

int frogJump(int n, vector<int>&heights)
{
    // Write your code here.
    vector<int>dp(n , -1);
   return memoization(n-1 , heights , dp);    
}

/****************Solution for Frog jump using Tabulation*******************/
/****************Time Complexity = O(N)*************************************/
/****************Space Complexity = O(N)************************************/

int frogJump(int n, vector<int>&heights)
{
    // Write your code here.
    
    vector<int>dp(n);
    dp[0] = 0;

    for(int i = 1 ; i < n ; i++) {
        int left = INT_MAX , right = INT_MAX;
        if(i-1 >= 0)
             left = dp[i-1] + abs(heights[i]  - heights[i-1]);
        if(i - 2 >= 0)
            right = dp[i-2] + abs(heights[i] - heights[i-2]);
       
        dp[i] = min(left , right);
    }

    return dp[n-1];   
}


/****************Space Optimized Solution for Frog jump*********************/
/****************Time Complexity = O(N)*************************************/
/****************Space Complexity = O(1)************************************/

int frogJump(int n, vector<int>&heights)
{
    // Write your code here.
    int prev1 = 0 , prev2;
    for(int i = 1 ; i < n ; i++) {
        int left = INT_MAX , right = INT_MAX;
        if(i-1 >= 0)
             left = dp[i-1] + abs(heights[i]  - heights[i-1]);
        if(i - 2 >= 0)
            right = dp[i-2] + abs(heights[i] - heights[i-2]);
        prev2 = prev1;
        prev1 = min(left , right);
    }

    return prev1;
}
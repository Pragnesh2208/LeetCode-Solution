#include <bits/stdc++.h> 

int helper(int row, int col , vector<vector<int>>&matrix , vector<vector<int>>&dp) {
    if(col < 0 || col >= matrix[0].size() ) return INT_MIN;
    else if(row == 0) return dp[row][col] = matrix[row][col];
    else  if(dp[row][col] == INT_MIN){
        int left = helper(row - 1 , col - 1 , matrix , dp);
        int middle = helper(row - 1 , col ,matrix , dp);
        int right = helper(row - 1, col + 1 , matrix , dp);
        if(left == INT_MIN) dp[row][col] = max(matrix[row][col] + right ,matrix[row][col] + middle) ;
        else if(right == INT_MIN) dp[row][col] = max( matrix[row][col] + middle , matrix[row][col] + left);
        else dp[row][col] = max(matrix[row][col] + left , max( matrix[row][col] + middle  , matrix[row][col] + right));
    }
    return dp[row][col];
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n , vector<int>(m , INT_MIN));
    for(int i = 0 ; i < m ;i++) {
        helper(n - 1 , i  , matrix , dp);  
    }
    
    int ans = INT_MIN;
    for(int i = 0 ; i < m ;i++) 
        ans = max(ans , dp[n-1][i]);
    return ans;   
}



#include <bits/stdc++.h> 

int helper(vector<vector<int>>&matrix , vector<vector<int>>&dp) {
    int totalRow = matrix.size() , totalCol = matrix[0].size();

    for(int col = 0 ; col < totalCol ; col++)dp[0][col] = matrix[0][col];
    for(int row = 1 ; row < totalRow ; row++) {
       for(int col = 0 ; col < totalCol ; col++) {
           int curCell = matrix[row][col];
           dp[row][col] = curCell + dp[row - 1][col];
           if(col  > 0) dp[row][col] = max(curCell + dp[row- 1][col - 1] , dp[row][col]);
           if(col + 1 < totalCol) dp[row][col] = max(curCell + dp[row - 1][col + 1] , dp[row][col]);
       }
   }
   int ans = INT_MIN;
   for(int col = 0 ; col < totalCol; col++) {
       ans = max(dp[totalRow - 1][col] , ans);
   } 
   return ans;
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n , vector<int>(m , INT_MIN));
   
    return helper(matrix , dp);  
    
   
}


#include <bits/stdc++.h> 

int helper(vector<vector<int>>&matrix) {
    int totalRow = matrix.size() , totalCol = matrix[0].size();
    vector<int>prevRow(totalCol , INT_MIN);
    for(int col = 0 ; col < totalCol ; col++)prevRow[col] = matrix[0][col];
    for(int row = 1 ; row < totalRow ; row++) {
        vector<int>curRow(totalCol , INT_MIN);
       for(int col = 0 ; col < totalCol ; col++) {
           int curCell = matrix[row][col];
           curRow[col] = curCell + prevRow[col];
           if(col  > 0) curRow[col] = max(curCell + prevRow[col - 1] , curRow[col]);
           if(col + 1 < totalCol) curRow[col] = max(curCell + prevRow[col + 1] , curRow[col]);
       }
       prevRow = curRow;
   }
   int ans = INT_MIN;
   for(int col = 0 ; col < totalCol; col++) {
       ans = max(prevRow[col] , ans);
   } 
   return ans;
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    return helper(matrix);  
}
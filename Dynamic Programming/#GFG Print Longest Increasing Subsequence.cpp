/**
 * Solution using memoization
 * Time complexity = O(N^2)
 * Space Complexity = O(N^2)
 */
class Solution {
  public:
    int solve(int ind , int prevInd , vector<int>&arr , vector<vector<int>>&dp) {
        int n = arr.size();
        if(ind == n) return 0;
        if(dp[ind][prevInd + 1] != -1) return dp[ind][prevInd + 1];
        int take = prevInd == -1 || arr[ind] > arr[prevInd] ? solve(ind + 1 , ind, arr , dp ) + 1 : 0;
        int notTake = solve(ind + 1 , prevInd ,arr , dp);
        
        return dp[ind][prevInd + 1] =  max(take , notTake);
    }
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<vector<int>>dp(n + 1 , vector<int>(n + 1 , -1));
        vector<int>ans;
        solve(0 , -1 , arr , dp);
        for(int i = 0 ; i <= n ; i++) dp[n][i] = 0;
        int ind = 0 , prevInd = -1;
        
        while(ans.size() != dp[0][0] && ind < n) {
            bool flag = true;
            if(ans.size()) flag = ans.back() < arr[ind];
            if( flag && dp[ind ][prevInd + 1] == dp[ind + 1][ind + 1] + 1) {
               ans.push_back(arr[ind]);
               prevInd = ind;
               ind++;
            } else ind++;
        }
        
        return ans;
    }
};
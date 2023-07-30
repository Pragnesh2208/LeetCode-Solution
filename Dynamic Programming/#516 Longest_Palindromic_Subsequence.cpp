/*
Time Complexity = O(N^2)
Space Complexity = O(N^2)
we can convert space complexity to O(N) by using curr and prev array 
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string revs ="";
        int n = s.size();
        for(int i = n - 1; i >= 0 ; i--) revs.push_back(s[i]);
        vector<vector<int>>dp(n + 1 , vector<int>(n + 1 , 0));
        for(int i = 1 ; i <= n ;i++){
            for(int j = 1; j <= n ;j++) {
                if(s[i-1] == revs[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};
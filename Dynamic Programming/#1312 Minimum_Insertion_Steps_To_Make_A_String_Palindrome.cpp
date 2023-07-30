/*
Time Complexity = O(N^2)
Space Complexity = O(N^2)
*/
class Solution {
public:
    int minInsertions(string s) {
        string s2 = s;
        int n = s.size();
        int i = 0 , j = n - 1;
        while(i < j) swap(s2[i++],s2[j--]);
        vector<vector<int>>dp(n + 1 , vector<int>(n + 1 , 0));

        for(int i = 1 ;  i <= n ; i++) {
            for(int j = 1 ; j <= n ; j++) {
                if(s[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return n - dp[n][n];
    }
};
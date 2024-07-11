/******************************Optimal Approach to solve Delete Operation for Two String***************/
/******************************Time Complexity is O(N * M)*********************************************/
/******************************Space Complexity is O(N + M)************************************************/

class Solution {
    int solve(int ind1 , int ind2 , string &s1 , string &s2 , vector<vector<int>>&dp) {
        int n = s1.length();
        int m = s2.length();

        if(ind1 == n || ind2 == m) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(s1[ind1] == s2[ind2]) return dp[ind1][ind2] = solve(ind1 + 1 , ind2 + 1 , s1 , s2 , dp) + 1;
        return dp[ind1][ind2] =  max(solve(ind1 + 1 , ind2 , s1 , s2 , dp) , solve(ind1 , ind2 + 1 , s1 , s2 , dp));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n , vector<int>( m , -1));
        solve(0 , 0 , word1 , word2 , dp);
        return n + m - 2 * dp[0][0];
    }
};
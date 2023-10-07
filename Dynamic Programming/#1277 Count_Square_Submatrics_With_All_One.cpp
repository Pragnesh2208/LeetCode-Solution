/*
Solution Using Tabulation
Time Complexity = O(m * n)
Space Complexity = O(m * n)
*/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<vector<int>>dp(n + 1 , vector<int>(m + 1, 0));
        int maxSqure = 0; 

        for(int i = 1 ; i <= n ; i++) {
            for(int j = 1 ; j <= m ; j++){
                if(matrix[i - 1][j - 1])
                dp[i][j] = min(dp[i-1][j] , min(dp[i-1][j-1] , dp[i][j-1])) + 1;
                maxSqure += dp[i][j];
            }
        }
        return maxSqure;
    }
};
/*
Time Complexity = O(N*M)
Space Complexity = O(N*M)
Using Memoization
*/
class Solution {
    private:
    int backtracking(string &str1 , string &str2 , int i , int j , vector<vector<int>>&dp) {
        if(i < 0 ) return j + 1;
        if(j < 0 ) return i + 1;
        if(dp[i][j] != -1) return dp[i][j];

        if(str1[i] == str2[j])
        return dp[i][j] = backtracking(str1 , str2 , i - 1, j - 1 , dp);
        else 
       return dp[i][j] =  min (backtracking(str1 , str2 , i - 1 , j , dp) + 1 , min(  backtracking(str1 , str2 , i - 1, j - 1 , dp) + 1 , backtracking(str1 , str2 , i , j - 1 , dp) + 1) ); 

    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size() , m = word2.size();
        vector<vector<int>>dp( n , vector<int>(m , -1) );
       return backtracking(word1 , word2 , n - 1 , m  - 1 , dp);
    }
};

/*
Time Complexity = O(N*M)
Space Complexity = O(N*M)
Using Tabulation
*/
class Solution {
    private:

    int tabulation(string &s1  , string &s2) {
        int n = s1.size() , m = s2.size();
        vector<vector<int>>dp(n + 1 , vector<int>(m + 1 , 0));
      
        for(int i = 1 ; i <= m ; i++) dp[0][i] = i;
        for(int i = 1; i <= n ; i++) dp[i][0] = i;


        for(int i = 1 ;i <= n ; i++) { 
            for(int j = 1; j <= m ; j++) {
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = min(dp[i - 1][j] + 1 , min(dp[i-1][j-1] + 1 , dp[i][j-1] + 1));
                }
            }
        }
        return dp[n][m];
    }
public:
    int minDistance(string word1, string word2) {
        return tabulation(word1 , word2);
    }
};

/*
Time Complexity = O(N*M)
Space Complexity = O(N+M)
Using Space Optimization
*/
class Solution {
    private:

    int spaceOptimization(string &s1  , string &s2) {
        int n = s1.size() , m = s2.size();
        vector<int>prev(m + 1 , 0);
        for(int i = 1 ; i <= m ; i++) prev[i] = i;


        for(int i = 1 ;i <= n ; i++) { 
            vector<int>curr(m + 1 , 0);
            curr[0] = i;
            for(int j = 1; j <= m ; j++) {
                if(s1[i-1] == s2[j-1]) curr[j] = prev[j-1];
                else {
                    curr[j] = min(prev[j] + 1 , min(prev[j-1] + 1 , curr[j-1] + 1));
                }
            }
            prev = curr;
        }
        return prev[m];
    }
public:
    int minDistance(string word1, string word2) {
        return spaceOptimization(word1 , word2);
    }
};